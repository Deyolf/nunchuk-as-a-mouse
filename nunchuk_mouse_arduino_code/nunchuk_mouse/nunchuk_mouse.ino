//TUTORIAL ARDUINO 004 - UTILIZZARE UN NUNCHUK CON ARDUINO - WWW.PEOPLEM.COM
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

//Includiamo tutte le librerie utilizzate nel sistema
#include <ArduinoNunchuk.h>

//Creiamo gli oggetti Servo e Nunchuk
ArduinoNunchuk nunchuk = ArduinoNunchuk();

struct dataNunchuk{
  int Xanalog;
  int Yanalog;
  int Xaccel;
  int Yaccel;
  int Zaccel;
  int Cbutton;
  int Zbutton;
};

//Dichiariamo le variabili
dataNunchuk packet;

void setup(){
  Serial.begin(9600);
  nunchuk.init();
  delay(2000);
}

void loop(){
  //Legge i dati dal Nunchuk
  nunchuk.update();


  packet.Xanalog=Serial.println(nunchuk.analogX);
  packet.Yanalog=Serial.println(nunchuk.analogY);
  //packet.Xaccel=Serial.println(nunchuk.accelX);
  //packet.Yaccel=Serial.println(nunchuk.accelY);
  //packet.Zaccel=Serial.println(nunchuk.accelZ);
  packet.Zbutton=Serial.println(nunchuk.zButton);
  packet.Cbutton=Serial.println(nunchuk.cButton);

  //size_t x = Serial.print(packet);
  Serial.flush();
}