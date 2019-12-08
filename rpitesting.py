from time import sleep
from smbus2 import SMBusWrapper
address = 0x04
 
# Give the I2C device time to settle
sleep(2)
 
while 1:
    try:
        with SMBusWrapper(1) as bus:
            data1 = input("Enter the data to be sent : ")
            bus.write_i2c_block_data(address, 0, data1)
            print('Offset {}, data {}'.format(data1[0], data1[1]))
            
    except:
        print(' Oops! Error')
    
    # Decreasing delay may create more transmission errors.
    sleep(0.0005)