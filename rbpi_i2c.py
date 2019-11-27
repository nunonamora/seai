#RPi Pinouts

#I2C Pins 
#GPIO2 -> SDA
#GPIO3 -> SCL

#Import the Library Requreid 
import smbus
import time

# for RPI version 1, use "bus = smbus.SMBus(0)"
bus = smbus.SMBus(1)

# This is the address we setup in the Arduino Program
#Slave Address 1
address = 0x04

#Slave Address 2
address_2 = 0x05

def ConvertStringToBytes(src): 
  converted = [] 
  for b in src: 
    converted.append(ord(b)) 
 
  return converted</pre>

while True:
	#Receives the data from the User
    data = input("Enter the data to be sent : ")
    BytesToSend = ConvertStringToBytes(data)
    bus.write_i2c_block_data(address, 0x00, BytesToSend)
    bus.write_i2c_block_data(address_2, 0x00, BytesToSend)  
    print("Sent " + address + " the " + data + " command.")
    print("Sent " + address_2 + " the " + data + " command.")


#End of the Script