-I2C(Inter-Integrated Circuit) is a serial communication protocol. It provides good support to the slow devices, 
 for example, EEPROM, ADC, I2C LCD, and RTC etc.
-I2C is basically a two-wire communication protocol. It uses only two wire for 
 communication. In which one wire is used for the data (SDA) and other wire 
 is used for the clock (SCL)
-In I2C, both buses are bidirectional, which means master able to 
 send and receive the data from the slave.
-Additionally, an I2C bus is used in the various control architecture, 
 for example, SMBus (System Management Bus), PMBus (Power Management Bus),
 IPMI (Intelligent Platform Management Interface) etc. 
-SPI is half duplex half-duplex, Synchronous Communication

-I2C is pure master and slave communication protocol, it can be the multi-master 
 or multi-slave but we generally see a single master in I2C communication.

-All slave and master are connected with same data and clock bus,
 here important thing is to remember these buses are connected to each other 
 using the WIRE-AND configuration which is done by to putting both pins is open drain.
 The wire-AND configuration allows in I2C to connect multiple nodes to the bus without 
 any short circuits from signal contention.

Operation:
-I2C is a  chip to chip communication protocol. 
-In I2C, communication is always started by the master.
-When the master wants to communicate with slave then he asserts a start bit followed by 
 the slave address with read/write bit.
-After asserting the start bit, all slave comes in the attentive mode.
-If the transmitted address match with any of the slave on the bus then an ACKNOWLEDGEMENT
 (ACK) bit is sent by the slave to the master.
-After getting the ACK bit, master starts the communication. 
-If there is no slave whose address match with the transmitted address then master received a
 NOT-ACKNOWLEDGEMENT (NACK) bit, in that situation either master assert the stop bit to stop 
 the communication or assert a repeated start bit on the line for new communication.
-When we send or receive the bytes in i2c, we always get a NACK bit or ACK bit after 
 each byte of the data is transferred during the communication.
-In I2C, one bit is always transmitted on every clock. A byte which is transmitted in I2C could
 be an address of the device, the address of register or data which is written to or read from the slave.
-In I2C, SDA line is always stable during the high clock phase except for 
 the start condition, stop condition and repeated start condition. 
 The SDA line only changes their state during the low clock phase.

_______________________________________________________________________________________________________
|START| 7or10 Bits addr|read/write bit|ACK/NACK bit|8bit data|ACK/NACK bit|8bit data|ACK/NACK bit| stop|
````````````````````````````````````````````````````````````````````````````````````````````````````````
*Start Condition:
 The default state of SDA and SCL line is high. A master asserts the start condition on the 
 line to start the communication. A high to low transition of the SDA line while the SCL line
 is high called the START condition. The START condition is always asserted by the master.
 The I2C bus is considered busy after the assertion of the START bit.
*Stop Condition:
 The STOP condition is asserted by the master to stop the communication. A Low to high 
 transition of SDA line while the SCL line is high called the STOP condition. 
 The STOP condition is always asserted by the master. 
 The I2C bus is considered free after the assertion of the STOP bit.

-The arbitration is required in the case of a multi-master, where more than one master is 
 tried to communicate with a slave simultaneously. In I2C arbitration is achieved by the SDA line.

What is I2C clock stretching?The clock stretching is the way in which slave drive the 
SCL line but it is the fact, most of the slave does not drive the SCL line


*Advantages of I2C communication
It follows the master and slave relationships.
It has the capability to handle multiple masters and multiple slaves on the I2C Bus.
I2C has some important features like arbitration, clock synchronization, and clock stretching.
I2C provides ACK/NACK (acknowledgment/ Not-acknowledgement) features that provide help in error handling.
It is the synchronous communication protocol, so there is no need of a precise oscillator for the master and slave.
It requires only two-wire, one wire for the data (SDA) and other wire for the clock (SCL).
It provides the flexibility to the user to select the transmission rate as per the requirements.
In I2C bus, each device on the bus is independently addressable


*limitations of I2C interface
Half-duplex communication, so data is transmitted only in one direction (because of the single data bus) at a time.
Since the bus is shared by many devices, debugging an I2C bus (detecting which device is misbehaving) for issues is pretty difficult.
The I2C bus is shared by multiple slave devices if anyone of these slaves misbehaves (pull either SCL or SDA low for an indefinite time) the bus will be stalled. No further communication will take place.
I2C uses resistive pull-up for its bus. Limiting the bus speed.
Bus speed is directly dependent on the bus capacitance, meaning longer I2C bus traces will limit the bus speed.

*one master at a time can address - 127slaves



===============================================================================================================================================================================================
