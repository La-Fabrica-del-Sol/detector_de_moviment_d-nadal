# Arbol de navidad
*Creado por Will, Lorea, Maria, & Bea en 26 Nov 2019 para un taller de la Fàbrica del Sol*

- **Què es?** Es un arbol de navidad con luces.
- **Per a què serveix?**  Ahorra electricidad comparado con otros arboles de navidad, porque las luces solo se enciendan cuando hay gente cerca para verlas.
- **Puc jugar amb ell?** Sí! Puedes hacer que las luces cambien de color con una palmada.
- **Puc crear el meu pròpi arbre de nadal?** Sí! Vegeu les instruccions a continuació.

## Materials
**1. Arduino Uno**

El Arduino Uno es la version más popular del microcontrolador. Se puede alimentar con su cable USB a 5 voltios o con el jack DC con 7-12 voltios.

<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/arduino_uno.jpg" width=500>

**2. Escudo 'breakout' o cables dupont para hacer las conexiones**

Nosotros hemos usado el kit de Arduino del [Seed Studio](https://www.seeedstudio.com/Grove-Starter-Kit-for-Arduino-p-1855.html) con el escudo 'breakout' para minimizar el cableado de las varias conexiones. 

<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/breakout.jpg" width=500>

**3. Módulo de sensor de sonido (micrófono piezo)**

Este módulo del kit de Seed Studio nos deja detectar las palmadas- por supuesto se puede utilizar modulos de sensor de sonido de otros modelos. Este módulo contiene un micrófono que envia un señal análogo al Arduino (de 0 a 1023) dependiendo del nivel de sonido que detecta.

<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/sound_sensor.jpg" width=200>

**4. Módulo de sensor de movimiento (RCLW-0516)**

Este módulo es un sensor que funciona como el radar. Utiliza ondas electromagneticas para detectar cuando hay movimiento en una esfera de 3-4 menos a su entorno. Cuando está enchufado al Arduino, este modulo envia un señal digital de 1 (sí hay movimiento) o 0 (no hay moviemiento).

<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/rcwl-0516.jpg" width=300>

**5. 3x módulos de interruptor electrónico (relés)**

Los módulos de relés son como interruptores eléctricos que nos permitan encender y apagar los tiros de LEDs con el Arduino.

<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/relay.jpg" width=350>

**6. Tiro de LEDs RGB (SMD5050)**

Los tiros de LEDs RGB son bastante baratos y tienen muchos usos. 

<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/smd5050.jpg" width=210>

**7. Fuente de alimentación adecuada para los LEDs y el Arduino**

Necesitaremos una fuente de 12 voltios (y mas de 1 amperio) para el tiro de LEDs, que afortunadamente es apto para el Arduino tambien.

## Instrucciones
Aquí tienes una diagrama básica de las conexiónes. El Arduino y los LEDs están alimentados con 12 voltios, y los sensores y los relés están alimentados con la salida de 5 voltios del Arduino. 

<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/diagrama_arbol_navidad.jpg" width=1000>

Pusimos toda la electronica (el Arduino con los sensores) dentro de una caja de madera y metacrilato:
<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/arbol_caja_electronica.jpg" width=400>

Luego diseñamos el arbol y cortamos las formas de las ramas en cartón con la cortadora láser:
<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/arbol_desmontado.jpg" width=400>

Los niños tuvieron que trabajar juntos para montar el arbol usando las piezas de cartón:
<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/arbol_medio_montado.jpg" width=400>

Los niños diseñaron adornos para el arbol y gravamos sus dibujos en metracrilato:
<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/arbol_decoraciones_gravadas.jpg" width=400>

Una vez el arbol estaba totalmente montado, pusimos el tiro de LEDs y enchufamos el sistema de control:
<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/arbol_decoraciones_gravadas.jpg" width=400>

Las luces se encienden cuando el sensor de movimeinto detecta que hay gente cerca y luego se apaga automaticamente:
<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/arbol_luz_verde.jpg" width=400>

Cuando el sensor de audio detecta palmadas o otros sonidos fuertes, el arbol cambia de color:
<img src="https://github.com/La-Fabrica-del-Sol/detector_de_moviment_d-nadal/blob/master/img/arbol_luz_azul.jpg" width=400>

