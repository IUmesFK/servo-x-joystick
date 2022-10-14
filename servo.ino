#include <Servo.h> //Añadimos la libreria servo.

//Declaramos los servomotores.

Servo base; 
Servo brazo;
Servo hombro;
Servo gancho;

int stickX = 0; //Declaramos el pin analogico para el eje x del primer joystick.
int stickY = 1; //Declaramos el pin analogico para el eje y del primer joystick.
int stick_2X = 2; //Declaramos el pin analogico para el eje x del segundo joystick,
int stick_2Y = 3; //Declaramos el pin analogico para el eje y del segundo joystick.

int pulsador = 8; //Declaramos el pin del pulsador del primer joystick.
int pulsador2 = 9; //Declaramos el pin del pulsador del segundo joystick.

int pulsadorlec; //Estas variables almacenaran las lecturas de los pulsadores respectivamente.
int pulsadorlec2;

int servoval; //Esta variable servira para almacenar valores de 0 a 180, que es lo que se podra mover el servo.


void setup() {
  // put your setup code here, to run once:

  base.attach(3); //Declaramos los 4 pines de conexion de los servos.
  brazo.attach(4);
  hombro.attach(5);
  gancho.attach(6);

}

void loop() {
  // put your main code here, to run repeatedly:
int pulsadorlec = digitalRead (8); //Indicamos que se lea los valores del pin 8, el pin del pulsador del primer joystick.
int pulsadorlec2 = digitalRead (9); //Indicamos que se lea los valores del pin 9, el pin del pulsador del primer joystick.

if (pulsadorlec == LOW) { //Si la variable pulsadorlec es igual a LOW (no se ha presionado ninguna vez), se hara lo siguiente:

  servoval = analogRead(stickX); //Lectura del pin analogico del eje X del primer joystick.
  servoval = map(servoval, 0, 1023, 0, 180); //Se hace un mapeo de los valores del pin analogico.
  base.write(servoval); //Se posiciona al servo en el valor que nos de el pin analogico.

} if (pulsadorlec == HIGH) { //Si el valor de pulsadorlec es igual a HIGH (ha sido presionado) se hara lo siguiente:

  servoval = analogRead(stickY); //Lectura del pin analogico del eje Y del primer joystick.
  servoval = map(servoval, 0, 1023, 0, 180); //se mapean los valores del pin analogico.
  brazo.write(servoval); //se posiciona al servo en la posicion del joystick.

}



if (pulsadorlec2 == LOW) { //Si la variable pulsadorlec2 es igual a LOW (no se ha presionado ninguna vez), se hara lo siguiente:

  servoval = analogRead(stick_2X); //Lectura del pin analogico del eje X del segundo joystick.
  servoval = map(servoval, 0, 1023, 0, 180);  //se mapean los valores del pin analogico.
  hombro.write(servoval);  //se posiciona al servo en la posicion del joystick.

} if (pulsadorlec2 == HIGH) { //

  servoval = analogRead(stick_2Y); //Lectura del pin analogico del eje X del segundo joystick.
  servoval = map(servoval, 0, 1023, 0, 180); //se mapean los valores del pin analogico.
  gancho.write(servoval); //se posiciona al servo en la posicion del joystick.

}


}
