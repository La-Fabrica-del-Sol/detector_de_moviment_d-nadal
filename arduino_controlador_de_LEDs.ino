/*
Proyecto de Arduino: arbol de navidad para un taller de la Fàbrica del Sol
Para usar con la placa Arduino Uno (R3)
Will Lorea & Maria 26 Nov 2019

*/


// PRIMERA SECCIÓN: DEFENIMOS LAS VARIABLES (GLOBALES)

int MOVEMENT_SENSOR_PIN=7; // definir en cuál pin digital esta enchufado el output del sensor de movimiento (RCLW-0516)
int SOUND_SENSOR_PIN=A1; //definir en cuál pin análogo esta enchufado el output del sensor de sonido
int RED_LED_PIN=4; //definir en cuál pin esta enchufado el input del relé que esta conectado a los LEDs rojos
int GREEN_LED_PIN=3; //definir en cuál pin esta enchufado el input del relé que esta conectado a los LEDs verdes
int BLUE_LED_PIN=2; //definir en cuál pin esta enchufado el input del relé que esta conectado a los LEDs azules
boolean RedLEDStatus=false; //definir un boolean (true/false i.e. encendido/apagado) para marcar el estátus de los LEDs rojos
boolean GreenLEDStatus=false; //definir un boolean (true/false i.e. encendido/apagado) para marcar el estátus de los LEDs verdes
boolean BlueLEDStatus=false; //definir un boolean (true/false i.e. encendido/apagado) para marcar el estátus de los LEDs azules
int SoundLimit=360; // definir un límite de sonido (entre 0 y 1023) y si pasamos de ello, podremos actuar (p.e. encender o apagar LEDs)
int PreviousSoundSensorData=0; // crear un variable donde guardamos la última medida del valor del sensor de sonido



// SEGUNDA SECCION: LAS FUNCIONES BASICAS

void setup() {   // esta seccion de codigo se corre solo una vez, cuando el Arduino se despierta
  
  Serial.begin(9600); // abrimos un canal de comunicacion por Serial (USB) para que el Arduino nos pueda informar de los valores que dan los sensores
  pinMode(SOUND_SENSOR_PIN,INPUT); // decimos al Arduino que el pin donde tenemos el sensor de sonido enchufado sera para INPUT o sea para recibir informacion  
  pinMode(MOVEMENT_SENSOR_PIN,INPUT); // decimos al Arduino que el pin donde tenemos el sensor de movimiento enchufado sera para INPUT o sea para recibir informacion
  pinMode(RED_LED_PIN,OUTPUT); // decimos al Arduino que el pin donde tenemos enchufado el relé que controla los LEDs es para OUTPUT o sea para enviar informacion (on/off)
  pinMode(BLUE_LED_PIN,OUTPUT); // decimos al Arduino que el pin donde tenemos enchufado el relé que controla los LEDs es para OUTPUT o sea para enviar informacion (on/off)
  pinMode(GREEN_LED_PIN,OUTPUT); // decimos al Arduino que el pin donde tenemos enchufado el relé que controla los LEDs es para OUTPUT o sea para enviar informacion (on/off)

}



void loop() {  // esta seccion de codigo se corre continuamente (pero despues de la seccion de 'setup' arriba por supuesto)
  
  boolean MovementSensorData=digitalRead(MOVEMENT_SENSOR_PIN); //cogemos el valor del sensor de movimiento como un boolean (true/false i.e. 1 o 0)
  int SoundSensorData=analogRead(SOUND_SENSOR_PIN); // definimos un variable llamado 'SensorData' y le pasamos el valor del sensor de sonido en este momento con la funcion 'digitalRead'
  Serial.println(SoundSensorData); // durante cada iteración del bucle, esta linea nos imprime el valor que el sensor esta percibiendo

  if(MovementSensorData==true){  //si detectamos movimiento, hacemos lo siguente
    Serial.println("Movimiento detectado! Activando LEDs...");
    if(RedLEDStatus==false && GreenLEDStatus==false && BlueLEDStatus==false){ // una vez detectado movimiento, miramos si los LEDs están encendidos. Si estan todos apagados, encendemos los verdes. Si están encendidos, no hacemos nada.
      GreenLEDStatus=true; // 
      digitalWrite(GREEN_LED_PIN,HIGH); // enviamos el señal de "HIGH" al relé para que endienda los LEDs
      }else if(SoundSensorData-PreviousSoundSensorData>SoundLimit){ // si el valor recibido del sensor de sonido supera el valor previo por encima de nuestro limite, hacemos lo siguente
        Serial.println("Sonido detectado! Cambiando LEDs...");
        change_color(); //ejecutamos nuestra funcion llamado "change_color" que cambia el color de los LEDs activados
        delay(100); // esperemos 1/100 de un segundo despues de cambiar de color (para no cambiar de color demasiado rapido)
     }
  } else { // si no detectamos movimiento, apagamos todos los LEDs
      RedLEDStatus=false;
      digitalWrite(RED_LED_PIN,LOW);
      GreenLEDStatus=false;
      digitalWrite(GREEN_LED_PIN,LOW);
      BlueLEDStatus=false;
      digitalWrite(BLUE_LED_PIN,LOW);
  }
}


// TERCERA SECCION: FUNCIONES ESPECIALES

void change_color() { // creamos una funcion que cambia el color de los LEDs encendidos cada vez que lo llamamos en el codigo 
  Serial.println("Cambiando de color...");
  
  if(RedLEDStatus==false && GreenLEDStatus==true && BlueLEDStatus==false){ // si solo los LEDs verdes estan encendidos, apagamos los verdes y encendemos solo los rojos
    GreenLEDStatus=false;
    digitalWrite(GREEN_LED_PIN,LOW);
    RedLEDStatus=true;
    digitalWrite(RED_LED_PIN,HIGH);
   
  } else if(RedLEDStatus==true && GreenLEDStatus==false && BlueLEDStatus==false){ // si solo los LEDs rojos estan encendidos, apagamos los rojos y encendemos solo los azules
    RedLEDStatus=false;
    digitalWrite(RED_LED_PIN,LOW);
    BlueLEDStatus=true;
    digitalWrite(BLUE_LED_PIN,HIGH);
    
  } else if(RedLEDStatus==false && GreenLEDStatus==false && BlueLEDStatus==true){ // si solo los LEDs azules estan encendidos, encendemos los verdes tambien
    GreenLEDStatus=true;
    digitalWrite(GREEN_LED_PIN,HIGH);
    
  } else if(RedLEDStatus==false && GreenLEDStatus==true && BlueLEDStatus==true){ // si los LEDs azules y verdes estan encendidos, apagamos los azules y encendemos los rojos
    BlueLEDStatus=false;
    digitalWrite(BLUE_LED_PIN,LOW);
    RedLEDStatus=true;
    digitalWrite(RED_LED_PIN,HIGH);
    
  } else if(RedLEDStatus==true && GreenLEDStatus==true && BlueLEDStatus==false){ // si los LEDs rojos y verdes estan encendidos, apagamos los verdes y encendemos los azules
    GreenLEDStatus=false;
    digitalWrite(GREEN_LED_PIN,LOW);
    BlueLEDStatus=true;
    digitalWrite(BLUE_LED_PIN,HIGH);
    
  } else if(RedLEDStatus==true && GreenLEDStatus==false && BlueLEDStatus==true){ // si los LEDs rojos y azules estan encendidos, encendemos los verdes tambien
    GreenLEDStatus=true;
    digitalWrite(GREEN_LED_PIN,HIGH);
  
  } else { // si no es uno de los casos anteriores, volvemos a encender solo los LEDs verdes
     RedLEDStatus=false;
     digitalWrite(RED_LED_PIN,LOW);
     BlueLEDStatus=false;
     digitalWrite(BLUE_LED_PIN,LOW);
     GreenLEDStatus=true;
     digitalWrite(GREEN_LED_PIN,HIGH);
  }
}


