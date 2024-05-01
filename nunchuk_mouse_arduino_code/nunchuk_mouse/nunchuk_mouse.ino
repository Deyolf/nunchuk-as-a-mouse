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
}

void loop(){
  //Legge i dati dal Nunchuk
  nunchuk.update();

  packet.Xanalog=nunchuk.analogX;
  packet.Yanalog=nunchuk.analogY;
  packet.Xaccel=nunchuk.accelX;
  packet.Yaccel=nunchuk.accelY;
  packet.Zaccel=nunchuk.accelZ;
  packet.Zbutton=nunchuk.zButton;
  packet.Cbutton=nunchuk.cButton;

  size_t x = Serial.write((byte*) &packet, sizeof(packet));
  Serial.flush();
}