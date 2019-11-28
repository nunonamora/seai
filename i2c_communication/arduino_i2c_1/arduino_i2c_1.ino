/*
  I2C Pinouts

  SDA -> A4
  SCL -> A5
*/

//Import the library required
#include <dht.h>
#include <Wire.h>

//Slave Address for the Communication
#define SLAVE_ADDRESS 0x04
#define dht_apin A0 // Analog Pin sensor is connected to
 

 

char number[50];
int state = 0;
int i = 0;
String  wire_in = "";
dht DHT;


//Code Initialization
void setup() {
  // initialize i2c as slave
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS);
  // define callbacks for i2c communication
  Wire.onReceive(receiveData);
  //  Wire.onRequest(sendData);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}

void loop() {
  DHT.read11(dht_apin);
  delay(50);
  if(wire_in.equals("1")){
     readTemp();
     i=0;
     wire_in = ""; 
  }else if(wire_in.equals("2")){
     readHum();
     i=0;
     wire_in = "";
  }
   else if(wire_in.equals("a")){
     readHum();
     i=0;
     wire_in = "";  
  }else{
    Serial.print(wire_in);
    wire_in = ""; 
  }
  

} // end loop

// callback for received data
void receiveData(int byteCount) {

    while(Wire.available()) // loop through all but the last
  {
      char c = Wire.read(); // receive byte as a character
      wire_in.concat(c);
     delay(10);
     Serial.print("Data in - ");         // print the character
  }
 
  delay(50);
}  // end while

// callback for sending data
void sendData() {
  Wire.write(number);
}

void readTemp(){
   Serial.println("\n");
   Serial.print("temperature = ");
   Serial.print(DHT.temperature); 
   Serial.println("C  ");
}


void readHum(){
   Serial.print("Current humidity = ");
   Serial.print(DHT.humidity);
   Serial.print("%  ");
}

//End of the program
