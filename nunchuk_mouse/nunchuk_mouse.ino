//TUTORIAL ARDUINO 004 - UTILIZZARE UN NUNCHUK CON ARDUINO - WWW.PEOPLEM.COM
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

//Includiamo tutte le librerie utilizzate nel sistema
#include <ArduinoNunchuk.h>

//Creiamo gli oggetti Servo e Nunchuk
ArduinoNunchuk nunchuk = ArduinoNunchuk();

//Dichiariamo le variabili
int c, z, xa, ya, xc, yc, zc;
int xmax=0, xmin=1000, ymax=0, ymin=1000;

void setup(){
  Serial.begin(9600);
  nunchuk.init();
}

void loop(){
  //Legge i dati dal Nunchuk
  nunchuk.update();
  
  //DEBUG SERIALE
  //Valori del joystick
  /*Serial.print("Xanalog:  ");
  Serial.print(nunchuk.analogX, DEC);
  Serial.print(' ');
  Serial.print("Yanalog:  ");
  Serial.print(nunchuk.analogY, DEC);
  Serial.print(' ');
  //Valori accellerometro
  Serial.print("Xaccel:  ");
  Serial.print(nunchuk.accelX, DEC);
  Serial.print(' ');
  Serial.print("Yaccel:  ");
  Serial.print(nunchuk.accelY, DEC);
  Serial.print(' ');
  Serial.print("Zaccel:  ");
  Serial.print(nunchuk.accelZ, DEC);
  
  Serial.println(' ');
  Serial.print("Z:  ");
  Serial.print(nunchuk.zButton, DEC);
  
  Serial.print(' ');
  Serial.print("C:  ");
  Serial.println(nunchuk.cButton);*/

  xa=nunchuk.analogX;
  ya=nunchuk.analogY;
  xc=nunchuk.accelX;
  yc=nunchuk.accelY;
  zc=nunchuk.accelZ;
  z=nunchuk.zButton;
  c=nunchuk.cButton;

  int xmove,ymove;

  xmove=map(xa,30,230,-2,3);
  ymove=map(ya,30,230,-2,3);
  Serial.print(xmove);
  Serial.print("   ");
  Serial.println(ymove);

  if (c==1){
    Serial.println("sx_beg");
    while(c==1){
      nunchuk.update();
      c=nunchuk.cButton;
    }
    Serial.println("sx_end");
  }
  if (z==1){
    Serial.println("dx_beg");
    while(z==1){
      nunchuk.update();
      z=nunchuk.zButton;
    }
    Serial.println("dx_end");
  }
  if (xa<xmin){
    xmin=xa;
  }
  if (xa>xmax){
    xmax=xa;
  }
  if (ya<ymin){
    ymin=ya;
  }
  if (ya>ymax){
    ymax=ya;
  }
}