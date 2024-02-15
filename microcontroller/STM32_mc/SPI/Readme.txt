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

SPI block diagram (ref manual):
-shift register upto 16bits,and we have control register sets for baudrate and SPI 
-MOSI and MISO connected to shift register and shift reg connected to TX,RX  buffer which are inturn connected to Addr and data bus(APB)
-if shift reg recives all the bits its move to RX buffer from that we can read the data through APB bus.
-and whenever you want to transmit data you write to TX buffer,if SPI  shift reg is free its loaded with TX buffer and further sent to MOSI pin
-there will be inturrupt for TX buffer empty we have to load the data, and there will be inturrupt when RX buffer is full 

-SCK internally connected to Baudrate generator(control reg)
-NSS slave select pin :
	1.when a device is slave mode:
	  the NSS works as a standard "chip seelect" input and lets the slave communicate with master
	2.when a decice is master:
	  the NSS can be used either as o/p or i/p.As an i/p it can prevent multi-master bus collition,and as o/p it 
	  can drive a slave select signal of a single slave
-Two types of slave mgmt (scenario of single master single slave)
   software NSS mgmt -> without using pin,if ssm=1 ssi=0 NSS pin will be grounded internally (slave side)
   h/w mgmt-> actually using pin
  
SPI Communication Format:
  based on clock polarity and phase
  1. SCLK phase(CPHA) {serial clock Phase}
  2. SClK Polarity(CPOL)
  3. Data frame format

What is max SCLK speed of SPIx peripheral,for that we need to know speed of APBx bus on which spi is connected(8MHz)


 


