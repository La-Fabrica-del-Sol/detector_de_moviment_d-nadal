/*
Proyecto de Arduino: arbol de navidad para taller de la Fabrica del Sol
Para usar con la placa Arduino Uno (R3)
Will Lorea & Maria 26 Nov 2019

*/

// PRIMERO, UNA SECCION DONDE DEFENIMOS LOS VARIABLES (GLOBALES)

int movementSensorPin=5;
// definir en cual pin esta enchufado el sensor de movimiento

int soundSensorPin=A1; 
//definir en cual pin esta enchufado el sensor de sonido

int LEDPin=4; 
//definir en cual pin esta enchufado el rele que esta conectado a los LEDs

boolean LEDStatus=false; 
//definir un boolean (true/false=on/off) para marcar el estatus de los LEDs

int SoundLimit=360;
// definir un limite de sonido, y si pasamos de ello, actuamos (p.e. enciende los LEDs)

int PreviousSensorData=0;
// crear un variable donde guardamos la ultima medida del valor del sensor de sonido

// SEGUNDA SECCION: LAS FUNCIONES BASICAS

void setup() {   
 // esta seccion de codigo se corre una vez al principio cuando el Arduino se despierta

 Serial.begin(9600);
 // abrimos un canal de comunicacion por Serial (USB)
 
 pinMode(soundSensorPin,INPUT);
 // decimos al Arduino que el pin donde tenemos el sensor de sonido enchufado sera para INPUT o sea para recibir informacion

  pinMode(movementSensorPin,INPUT);
 // decimos al Arduino que el pin donde tenemos el sensor de movimiento enchufado sera para INPUT o sea para recibir informacion
 
 pinMode(LEDPin,OUTPUT);
 // decimos al Arduino que el pin donde tenemos enchufado el rele que controla los LEDs es para OUTPUT o sea para enviar informacion (on/off)

}



void loop() { 
  // esta seccion de codigo se corre continuamente (pero despues de la seccion de 'setup' arriba por supuesto)
  
  int SensorData=analogRead(soundSensorPin); 
  // definimos un variable llamado 'SensorData' y le pasamos el valor del sensor de sonido en este momento con la funcion 'digitalRead'

  boolean MovementSensorData=digitalRead(movementSensorPin);
  //cogemos el valor del sensor de movimiento 

  Serial.println(MovementSensorData);
  
  Serial.println(SensorData);
  // cada iteracion del bucle nos va a imprimir el valor que el sensor esta percibiendo
  
  if(SensorData-PreviousSensorData>SoundLimit){
  // si el valor recibido del sensor de sonido es 1, hacemos lo siguente
    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LEDPin,HIGH);
        Serial.println("Sound detected!\nActivating LEDs...");
        delay(1000);
    }
    else{
        LEDStatus=false;
        digitalWrite(LEDPin,LOW);
    }
  } PreviousSensorData=SensorData;
 } 
