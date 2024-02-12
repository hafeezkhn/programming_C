-------------------------------------------------------------------------------------------------------------------------------
-serial peripheral interface.is communication protocol,  SPI is developed by Motorola.
-The serial peripheral interface is four wire-based(can be 2 wires) 
 full-duplex(bcz you have 2 deticated lines, but can be configured for half duplex and simplex ) 
 these wire generally known as 
 1.MOSI (master out slave in), 
 2.MISO (master in slave out), 
 3.SCL (a serial clock which produces by the master) 
 4.SS (slave select line which use to select specific slave during the communication).
-slave can be SENSOR,EEPROM,SDCARD,DISPLAY,BLUETOOTH,etc....
-SPI,I2C these peripherals communicate over TTL signalling in voltage range 0V to 5V hence short distance communication
-SPI follows the master and slave architecture and communication is always started by the master.
-SPI is a synchronous communication protocol because the clock is shared by the master and slave
-SPI is supported only multi-slave does not support multi-master and slaves are selected by 
 the slave select signal. 
-In SPI during the communication data is shifted out from the master (like a ring buffer)
 and shifted into the slave vice- versa through the shift register.
-one single cycle 'two actions' data send master to slave and slave to master is taking place
-In multi-slave the slave which are not been selected their MOSI & MISO pins will be at tristate(high impedence state)
 for isolating them from other ICs
-ss should be ground to select slave,
 once ss is grounded then master can send data and recieve data(ie,MISO,MOSI not in high impidence state)

*Advantages
-There is no start and stop bits, so the data can be streamed continuously without interruption.
-It supports full-duplex.
-No need for precision oscillators in slave devices as it uses a master’s clock.
-No complicated slave addressing system like I2C.
-Higher data transfer rate than I2C (almost twice as fast).
-Separate MISO and MOSI lines, so data can be sent and received at the same time.
-Simple software implementation.

*disadvantages
-If there is more than one slave in communication then the wiring will be complex.
-Uses four wires (I2C and UARTs use two).
-No acknowledgment that the data has been successfully received (I2C has this).
-No form of error checking like the parity bit in UART.
-It only allows for a single master.

-----------------------------------------------------------------------------------------------------------------------------------
[STM32FX]




