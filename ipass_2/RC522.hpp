#ifndef RC522_HPP
#define RC522_HPP

#include "hwlib.hpp"
#include "nfccontroler.hpp"

class RC522
{
private:

	hwlib::pin_out & sda;
	hwlib::spi_bus & spi;
	
	enum CMD {
		// commands
		Idle		= 0x00, // Cancels all running commands.
		Mem			= 0x01, // Writes 25 bytes from the FIFO buffer to the internal buffer.
		RandId		= 0x02, // Generates a 10-byte random ID number.
		CalcCRC		= 0x03, // Activates the CRC coprocessor or performs a self test.
		Transmit	= 0x04, // Transmit data from the FIFO buffer
		NoCmdChange = 0x07, // Can be used to modify the CmdReg bits without chaning the command.
		Recieve		= 0x08, // Activates the reciever circuits.
		Trancieve	= 0x0C, // Transmits data from the FIFO buffer and automatically activates the receiver after Transmit.
		//reserved	= 0x0D, // reserved for future use.
		MFAuthent	= 0x0E, // Performs the MIFARE standard authentication as a reader.
		SoftReset	= 0x0F  // Resets the MFRC522.
	};
	

	enum Reg {
		// register addresses
		// Page 0 Command and status registers
		
		/*reserved		= 0x00, << 1;// reserved for future use.*/
		CommandReg 		= 0x01 << 1,// Starts and stops command execution.
		ComIEnReg		= 0x02 << 1,// Control bits to enable and disable the passing of interrupt requests.
		DivIEnReg		= 0x03 << 1,// Control bits to enable and disable the passing of interrupt requests.
		ComIrqReg		= 0x04 << 1,// Interrupt request bits.
		DivIrqReg		= 0x05 << 1,// Interrupt request bits.
		ErrorReg		= 0x06 << 1,// Error bit register showing the error status of the last command executed.
		Status1Reg		= 0x07 << 1,// Contains status bits of the CRC, interupt and FIFO buffer.
		Status2Reg		= 0x08 << 1,// Contains status bits of the reciver, transmiter and data mode detector.
		FIFODataReg		= 0x09 << 1,// Input and output of 64 byte FIFO buffer.
		FIFOLevelReg	= 0x0A << 1,// Indicates the number of bytes stored in the FIFO buffer.
		WaterLevelReg	= 0x0B << 1,// Defines the level for the FIFO under- and overflow warning.
		ControlReg		= 0x0C << 1,// Miscellaneous control bits. Start and stop the timer and able to check validity of the last recieved byte.
		BitFarmingReg	= 0x0D << 1,// Adjustments for bit oriented frames.
		CollReg			= 0x0E << 1,// Defines the first bit-collision detected on the RF interface.
		/*reserved		= 0x0F << 1,// reserved for future use.*/
		
		// Page 1 Communication
		/*reserved		= 0x10 << 1,// reserved for future use.*/
		ModeReg			= 0x11 << 1,// Defines general mode settings for transmitting and recieving.
		TxModeReg		= 0x12 << 1,// Defines the data rate during transmission.
		RxModeReg		= 0x13 << 1,// Defines the data rate during reception.
		TxControlReg	= 0x14 << 1,// Controls the logical behaivior of the antenna driver pins TX1 and TX2.
		TxASKreg		= 0x15 << 1,// Controls transmit modulation settings.
		TxSelReg		= 0x16 << 1,// Selects the internal sources for the analog module.
		RxSelReg 		= 0x17 << 1,// Selects internal receiver settings.
		RxTresholdReg	= 0x18 << 1,// Selects tresholds for the bit decoder/
		DemodReg		= 0x19 << 1,// Defines Demodulator settings.
		/*reserved		= 0x1A << 1,// reserved for future use.*/
		/*reserved		= 0x1B << 1,// reserved for future use.*/
		MfTxReg			= 0x1C << 1,// Controls some MIFARE communication transmit registers.
		MfRxReg			= 0x1D << 1,// Controls the use of the parity bit for sending and revieving.
		/*reserved		= 0x1E << 1,// reserved for future use.*/
		SerialSpeedReg	= 0x1F << 1,// Selects the speed for the serial UART interface.
		
		// Page 2 Configuration
		/*reserved		= 0x20 << 1,// reserved for future use.*/
		CRCResultH		= 0x21 << 1,// Shows the MSB values of the CRC calculation.
		CRCResultL		= 0x22 << 1,// shows the LSB values of the CRC calculation.
		/*reserved		= 0x23 << 1,// reserved for future use.*/
		ModWidthReg		= 0x24 << 1,// Sets modulation width.
		/*reserved		= 0x25 << 1,// reserved for future use.*/
		RFCfgReg		= 0x26 << 1,// Configures the receiver gain.
		GsNReg			= 0x27 << 1,// Defines the conductance of the antenna driver pins TX1 and TX2 for the n-driver when the driver is sitched on.
		CWGsPReg		= 0x28 << 1,// Defines the conductance of the p-driver output during periods of no modulation.
		ModGsPReg		= 0x29 << 1,// Defines the conductance of the p-driver output during modulation.
		TmodeReg		= 0x2A << 1,// Defines the timer settings.
		TPrescalerReg	= 0x2B << 1,// Defines the timer settings.
		TReloadRegH		= 0x2C << 1,// Defines the 16-bit timer reload value Higer bits.
		TreloadRegL		= 0x2D << 1,// Defines the 16-bit timer relaod value Lower bits.
		TCounterValRegH	= 0x2E << 1,// Contains timer values higher bits.
		TcounterValRegL = 0x2F << 1,// Contains timer values lower bits.
		
		// page 3 Test
		/*reserved		= 0x30 << 1,// reserved for future use.*/
		TestSel1Reg		= 0x31 << 1,// General test signal configuration.
		TestSel2Reg		= 0x32 << 1,// Gereral test signal and PRBS control.
		TestPinEnReg	= 0x33 << 1,// Enables the test bus pin output driver.
		TestPinValueReg	= 0x34 << 1,// Defines the HIGH and LOW values for the test port D1 to D7 when it is used as I/O
		TestBusReg		= 0x35 << 1,// Shows the status of the internal test bus.
		AutoTestReg 	= 0x36 << 1,// Defines if the self test is starter on CalcCRC command.
		VersionReg 		= 0x37 << 1,// Returns the version of the chip.. version 2 sould return 92h.
		AnalogTestReg	= 0x38 << 1,// Determines the analog output signal at, and status of, pins AUX1 and AUX2.
		TestDAC1Reg		= 0x39 << 1,// Defines the test value for TestDAC1.
		TestDAC2Reg		= 0x3A << 1,// Defines the test value for TestDAC2.
		TestADCReg		= 0x3B << 1 // Shows the values of ADC I and Q channels.
		/*reserved		= 0x3C << 1,// reserved for future use.*/
		/*reserved		= 0x3D << 1,// reserved for future use.*/
		/*reserved		= 0x3E << 1,// reserved for future use.*/
		/*reserved		= 0x3F << 1 // reserved for future use.*/
	};
	
	/*enum IRQ {
		
	}*/
	
	byte readRegister( Reg a ){ 
		byte awnser[2];
		byte Register = ( a | 0x80);
		spi.write_and_read(sda, 2, &Register, awnser);
		return awnser[1];
	}
	
	void writeRegister(Reg a, byte value){
		byte send[] = {a, value};
		spi.write_and_read(sda, 2, send, nullptr);
	}
	
public:
	
	RC522(hwlib::pin_out & sda, hwlib::spi_bus & spi):
	sda(sda), spi(spi)
	{}
	
	int readFIFO(void){
		int output_size = (int)readRegister(FIFOLevelReg);
		
		if (output_size == 0){
			hwlib::cout << "The FIFO buffer is empty";
			return 0;
		}
		return (int)readRegister(FIFODataReg);
	}
	
	int readFIFO(int output[]){
		
		int output_size = (int)readRegister(FIFOLevelReg);
		
		if (output_size == 0){
			hwlib::cout << "The FIFO buffer is empty";
			return 0;
		}
		
		for (int i = 0; i < output_size; i++){
			output[i] = (int)readRegister(FIFODataReg);
		}
		
		return output_size;
	}
	
	int writeFIFO(byte value){
		
		if ((int)readRegister(FIFOLevelReg) == 64){
			hwlib::cout << "Cannot Write the fifo buffer is full \n";
		}
		
		writeRegister(FIFODataReg, value);
		return 0;
	}
	
	int writeFIFO(int byte_amount, byte data[]){
		
		if (byte_amount > 64){
			hwlib::cout << "The FIFO buffer has a maximum size of 64" << '\n';
			return 1;
		}
		
		if((int)readRegister(FIFOLevelReg) + byte_amount > 64){
			hwlib::cout << "Overflow warning. \n Writing to much data. \n the FIFO-buffer has" 
						<< 64 - (int)readRegister(FIFOLevelReg) << "byte(s) of space left to write to \n";
			return 1;
		}
		
		for(int i = 0; i < byte_amount; i++){
			writeRegister(FIFODataReg, data[i]);
		}
		return 0;
	}
	
	void selfTest(void){
		hwlib::cout << "Initializing selftest" << '\n';
		byte empty25[25] = {};
		int result[64];
		hwlib::cout << "Resetting FIFO buffer" << '\n';
		writeRegister(FIFOLevelReg, 0x80); //flushes the FIFO register
		hwlib::cout << "Resetting chip" << '\n';
		writeRegister(CommandReg , SoftReset);
		hwlib::wait_ms(5000);
		hwlib::cout << "Writing 25 empty bytes to internal memory" << '\n';
		writeFIFO(25, empty25);
		writeRegister(CommandReg, Mem); 
		hwlib::cout << "Setting registers for selftest" << '\n';
		writeRegister(AutoTestReg, 0x09); //Initializes the selftest to run on the CalcCRC command.
		hwlib::cout << "Writing final empty byte FIFO" << '\n';
		writeFIFO(0x00);
		hwlib::cout << "Running selftest" << '\n';
		writeRegister(CommandReg, CalcCRC);
		hwlib::wait_ms(5000);
		hwlib::cout << "Test results:" << '\n';
		int n = readFIFO(result);
		
		for (int i = 0; i < n; i++){
			if(i % 8 == 0){
				hwlib::cout << '\n';
			}
			hwlib::cout << hwlib::hex << hwlib::setw(2) << hwlib::setfill('0') << result[i] << ' ';
		}
	}
	
	void cardPoll (void){
		
		int output[64];
		
		writeFIFO(0x26);
		writeRegister(CommandReg, Transmit);
		int n = readFIFO(output);
		
		for (int i = 0; i < n; i++){
			if(i % 8 == 0){
				hwlib::cout << '\n';
			}
			hwlib::cout << hwlib::hex << hwlib::setw(2) << hwlib::setfill('0') << output[i] << ' ';
		}
	}
};

#endif // RC522_HPP
