//https://electronicprojectssite.wordpress.com/2016/06/03/8ch-ir-remote-controller-with-i2c-eeprom-using-arduino/
//http://tronixstuff.com/2011/03/16/tutorial-your-arduinos-inbuilt-eeprom/

#include <IRremote.h>
#include <EEPROM.h>


int receiver = 11; // IR Pin Connected to arduino pin no 11
/* Variable Declaration for Store incoming Values */
int on1;
int on2;
int on3;
int on4;
int on5;
int on6;
int on7;
int on8;

int Relay1 =8;
int Relay2 =7;
int Relay3 =3;
int Relay4 =4;
int Relay5 =20;
int Relay6 =21;
int Relay7 =5;
int Relay8 =6;

IRrecv irrecv(receiver);
decode_results results;
void setup() {
// put your setup code here, to run once:

pinMode(Relay1, OUTPUT);
pinMode(Relay2, OUTPUT);
pinMode(Relay3, OUTPUT);
pinMode(Relay4, OUTPUT);
pinMode(Relay5, OUTPUT);
pinMode(Relay6, OUTPUT);
pinMode(Relay7, OUTPUT);
pinMode(Relay8, OUTPUT);

irrecv.enableIRIn();

delay(100);


on1 = EEPROM.read(1);
digitalWrite(Relay1, on1 ? HIGH : LOW);
on2 = EEPROM.read(2);
digitalWrite(Relay2, on2 ? HIGH : LOW);
on3 = EEPROM.read(3);
digitalWrite(Relay3, on3 ? HIGH : LOW);
on4 = EEPROM.read(4);
digitalWrite(Relay4, on4 ? HIGH : LOW);
on5 = EEPROM.read(5);
digitalWrite(Relay5, on5 ? HIGH : LOW);
on6 = EEPROM.read(6);
digitalWrite(Relay6, on6 ? HIGH : LOW);
on7 = EEPROM.read(7);
digitalWrite(Relay7, on7 ? HIGH : LOW);
on8 = EEPROM.read(8);
digitalWrite(Relay8, on8 ? HIGH : LOW);
delay(100);
}

void loop() {
// put your main code here, to run repeatedly:

if (irrecv.decode(&results))
{
translateIR();
irrecv.resume();
}
}
void translateIR(){

switch(results.value){

case 0xE0E021DF:
on1 = !on1;
digitalWrite(Relay1, on1 ? HIGH : LOW);
EEPROM.write(1, on1);
delay(100);
break;

case 0xE0E7A05F:
on2 = !on2;
digitalWrite(Relay2, on2 ? HIGH : LOW);
EEPROM.write(2, on2);
delay(100);
break;

case 0xE0E9609F:
on3 = !on3;
digitalWrite(Relay3, on3 ? HIGH : LOW);
EEPROM.write(3, on3);
delay(100);
break;

case 0xE0E070EF:
on4 = !on4;
digitalWrite(Relay4, on4 ? HIGH : LOW);
EEPROM.write(4, on4);
delay(100);
break;

case 0xE0E0506F:
on5 = !on5;
digitalWrite(Relay5, on5 ? HIGH : LOW);
EEPROM.write(5, on5);
delay(100);
break;

case 0xE06050AF:
on6 = !on6;
digitalWrite(Relay6, on6 ? HIGH : LOW);
EEPROM.write(6, on6);
delay(100);
break;

case 0xE0E130CF:
on7 = !on7;
digitalWrite(Relay7, on7 ? HIGH : LOW);
EEPROM.write(7, on7);
delay(100);
break;

case 0xE0E6B04F:
on8 = !on8;
digitalWrite(Relay8, on8 ? HIGH : LOW);
EEPROM.write(8, on8);
delay(100);
break;

case 0xE0E040BF:
on1 = 0;
on2 = 0;
on3 = 0;
on4 = 0;
on5 = 0;
on6 = 0;
on7 = 0;
on8 = 0;
digitalWrite(Relay1, LOW);
EEPROM.write(1, on1);
digitalWrite(Relay2, LOW);
EEPROM.write(2, on2);
digitalWrite(Relay3, LOW);
EEPROM.write(3, on3);
digitalWrite(Relay4, LOW);
EEPROM.write(4, on4);
digitalWrite(Relay5, LOW);
EEPROM.write(5, on5);
digitalWrite(Relay6, LOW);
EEPROM.write(6, on6);
digitalWrite(Relay7, LOW);
EEPROM.write(7, on7);
digitalWrite(Relay8, LOW);
EEPROM.write(8, on8);
delay(100);
break;

default:
break;
}
delay (100);
}
