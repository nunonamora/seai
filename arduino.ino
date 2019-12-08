/*
 LCD part reference to:
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

#include <Wire.h>

#define SLAVE_ADDRESS 0x04

char data[50];
char enviarchar[50];
String enviar= "ola";

void setup() {
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  Wire.onReceive(receiveEvent);


}

void loop() {

  if(strcmp(data, "123") == 0){
    Serial.println("resultou");
    data[0]='\0';
  }
  if(strcmp(data, "1n3") == 0){
    Serial.println("resultoudenovo");
    data[0]='\0';
  }

}



void receiveEvent(int howMany) {
  Serial.println("entrei");
  int numOfBytes = Wire.available();
  //display number of bytes and cmd received, as bytes
  Serial.println("len:");
  Serial.println(numOfBytes);
  
  byte b = Wire.read();  //cmd
  //Serial.print(b);


  //display message received, as char
  int i=0;
  for(i; i<numOfBytes-1; i++){
    data[i] = Wire.read();   
  }

   data[i] = '\0';

   Serial.println(data);
}


void sendData() {
  enviar.toCharArray(enviarchar, 50);
  Wire.write(enviarchar);
  
}
