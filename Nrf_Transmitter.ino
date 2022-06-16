#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
int x_key = A0;                                               


//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  Serial.begin(9600);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
  pinMode (x_key, INPUT) ;                     
}
void loop()
{
int  x_pos = analogRead(x_key);  
  int x_posi = map(x_pos, 0, 1023, 0, 180); 
  radio.write(&x_posi, sizeof(x_posi));
  delay(100);
  Serial.println(x_posi);
}
