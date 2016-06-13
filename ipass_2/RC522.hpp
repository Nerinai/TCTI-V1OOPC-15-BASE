// ==========================================================================
//
// File      : RC522.hpp
// Part of   : nfccontroler library for V1IPAS
// Copyright : David de Jong (c) 2016
// Contact   : marijn_david@hotmail.com
//
// Implementation for functions on the Microcontroller side of the library.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
/// @file

/// Implementation of the microcontroller functions for the NFC-RC522 microcontroller.
///
/// This class contains microcontroller specific implementation for working with the NFC-RC522 micrcontroller.
/// This class follows the Decorator type of datastructure.
#ifndef RC522_HPP
#define RC522_HPP

#include "hwlib.hpp"
#include "nfccontroler.hpp"

class RC522 : public nfccontroler
{
private:
/// \codn INTERNAL
	hwlib::pin_out & sda;
	hwlib::pin_in_out & reset;
	hwlib::spi_bus & spi;
/// \endcodn
public:

/// Constructor for the NFC-RC522 mircontroller implementation.
///
/// The constructor uses two pin objects and one spi object.
/// Both of wich are defined in Hwlib.
/// The sda pin needs to be a pin_out, the reset pin needs to be a pin_in_out.
/// The spi object needs to be defined according to Hwlib's standard.
	RC522(hwlib::pin_out & sda, hwlib::pin_in_out & reset, hwlib::spi_bus & spi):
	sda(sda), reset(reset), spi(spi)
	{}
	

	enum class Keytype{
		// The 2 types of keys you can authenticate with.
		/// Starts authentication with key A.
		AuthwithA	= 0x60,
		/// Starts authentication with key B.
		AuthwithB	= 0x61  
	};
	
	enum class CMD {
		// commands
		/// Cancels all running commands.
		Idle		= 0x00,
		/// Writes 25 bytes from the FIFO buffer to the internal buffer.
		Mem			= 0x01,
		/// Generates a 10-byte random ID number.
		RandId		= 0x02,
		/// Activates the CRC coprocessor or performs a self test.
		CalcCRC		= 0x03,
		/// Transmit data from the FIFO buffer
		Transmit	= 0x04,
		/// Can be used to modify the CmdReg bits without chaning the command.
		NoCmdChange = 0x07,
		/// Activates the reciever circuits.
		Recieve		= 0x08,
		/// Transmits data from the FIFO buffer and automatically activates the receiver after Transmit.
		Trancieve	= 0x0C,
		//reserved	= 0x0D, // reserved for future use.
		/// Performs the MIFARE standard authentication as a reader.
		MFAuthent	= 0x0E,
		/// Resets the MFRC522.
		SoftReset	= 0x0F, 
	};
	
	enum class Reg {
		// register addresses
		// Page 0 Command and status registers
		
		/*reserved		= 0x00, << 1;// reserved for future use.*/
		/// Starts and stops command execution.
		CommandReg 		= 0x01 << 1,
		/// Control bits to enable and disable the passing of interrupt requests.
		ComIEnReg		= 0x02 << 1,
		/// Control bits to enable and disable the passing of interrupt requests.
		DivIEnReg		= 0x03 << 1,
		/// Interrupt request bits.
		ComIrqReg		= 0x04 << 1,
		/// Interrupt request bits.
		DivIrqReg		= 0x05 << 1,
		/// Error bit register showing the error status of the last command executed.
		ErrorReg		= 0x06 << 1,
		/// Contains status bits of the CRC, interupt and FIFO buffer.
		Status1Reg		= 0x07 << 1,
		/// Contains status bits of the reciver, transmiter and data mode detector.
		Status2Reg		= 0x08 << 1,
		/// Input and output of 64 byte FIFO buffer.
		FIFODataReg		= 0x09 << 1,
		/// Indicates the number of bytes stored in the FIFO buffer.
		FIFOLevelReg	= 0x0A << 1,
		/// Defines the level for the FIFO under- and overflow warning.
		WaterLevelReg	= 0x0B << 1,
		/// Miscellaneous control bits. Start and stop the timer and able to check validity of the last recieved byte.
		ControlReg		= 0x0C << 1,
		/// Adjustments for bit oriented frames.
		BitFramingReg	= 0x0D << 1,
		/// Defines the first bit-collision detected on the RF interface.
		CollReg			= 0x0E << 1,
		/*reserved		= 0x0F << 1,// reserved for future use.*/
		
		// Page 1 Communication
		/*reserved		= 0x10 << 1,// reserved for future use.*/
		/// Defines general mode settings for transmitting and recieving.
		ModeReg			= 0x11 << 1,
		/// Defines the data rate during transmission.
		TxModeReg		= 0x12 << 1,
		/// Defines the data rate during reception.
		RxModeReg		= 0x13 << 1,
		/// Controls the logical behaivior of the antenna driver pins TX1 and TX2.
		TxControlReg	= 0x14 << 1,
		/// Controls transmit modulation settings.
		TxASKreg		= 0x15 << 1,
		/// Selects the internal sources for the analog module.
		TxSelReg		= 0x16 << 1,
		/// Selects internal receiver settings.
		RxSelReg 		= 0x17 << 1,
		/// Selects tresholds for the bit decoder/
		RxTresholdReg	= 0x18 << 1,
		/// Defines Demodulator settings.
		DemodReg		= 0x19 << 1,
		/*reserved		= 0x1A << 1,// reserved for future use.*/
		/*reserved		= 0x1B << 1,// reserved for future use.*/
		/// Controls some MIFARE communication transmit registers.
		MfTxReg			= 0x1C << 1,
		/// Controls the use of the parity bit for sending and revieving.
		MfRxReg			= 0x1D << 1,
		/*reserved		= 0x1E << 1,// reserved for future use.*/
		/// Selects the speed for the serial UART interface.
		SerialSpeedReg	= 0x1F << 1,
		
		// Page 2 Configuration
		/*reserved		= 0x20 << 1,// reserved for future use.*/
		/// Shows the MSB values of the CRC calculation.
		CRCResultH		= 0x21 << 1,
		/// shows the LSB values of the CRC calculation.
		CRCResultL		= 0x22 << 1,
		/*reserved		= 0x23 << 1,// reserved for future use.*/
		/// Sets modulation width.
		ModWidthReg		= 0x24 << 1,
		/*reserved		= 0x25 << 1,// reserved for future use.*/
		/// Configures the receiver gain.
		RFCfgReg		= 0x26 << 1,
		/// Defines the conductance of the antenna driver pins TX1 and TX2 for the n-driver when the driver is sitched on.
		GsNReg			= 0x27 << 1,
		/// Defines the conductance of the p-driver output during periods of no modulation.
		CWGsPReg		= 0x28 << 1,
		/// Defines the conductance of the p-driver output during modulation.
		ModGsPReg		= 0x29 << 1,
		/// Defines the timer settings.
		TmodeReg		= 0x2A << 1,
		/// Defines the timer settings.
		TPrescalerReg	= 0x2B << 1,
		/// Defines the 16-bit timer reload value Higer bits.
		TReloadRegH		= 0x2C << 1,
		/// Defines the 16-bit timer relaod value Lower bits.
		TreloadRegL		= 0x2D << 1,
		/// Contains timer values higher bits.
		TCounterValRegH	= 0x2E << 1,
		/// Contains timer values lower bits.
		TcounterValRegL = 0x2F << 1,
		
		// page 3 Test
		/*reserved		= 0x30 << 1,// reserved for future use.*/
		/// General test signal configuration.
		TestSel1Reg		= 0x31 << 1,
		/// Gereral test signal and PRBS control.
		TestSel2Reg		= 0x32 << 1,
		/// Enables the test bus pin output driver.
		TestPinEnReg	= 0x33 << 1,
		/// Defines the HIGH and LOW values for the test port D1 to D7 when it is used as I/O
		TestPinValueReg	= 0x34 << 1,
		/// Shows the status of the internal test bus.
		TestBusReg		= 0x35 << 1,
		/// Defines if the self test is starter on CalcCRC command.
		AutoTestReg 	= 0x36 << 1,
		/// Returns the version of the microcontroller. For example version 2 sould return 92h.
		VersionReg 		= 0x37 << 1,
		/// Determines the analog output signal at, and status of, pins AUX1 and AUX2.
		AnalogTestReg	= 0x38 << 1,
		/// Defines the test value for TestDAC1.
		TestDAC1Reg		= 0x39 << 1,
		/// Defines the test value for TestDAC2.
		TestDAC2Reg		= 0x3A << 1,
		/// Shows the values of ADC I and Q channels.
		TestADCReg		= 0x3B << 1 
		/*reserved		= 0x3C << 1,// reserved for future use.*/
		/*reserved		= 0x3D << 1,// reserved for future use.*/
		/*reserved		= 0x3E << 1,// reserved for future use.*/
		/*reserved		= 0x3F << 1 // reserved for future use.*/
	};
/// \codn INTERNAL
	byte readRegister( Reg a ){ 
		return readRegister((byte)a);
	}
	
	byte readRegister( byte registerAddress ) override {
		byte awnser[2];
		byte Register = ( registerAddress | 0x80);
		spi.write_and_read(sda, 2, &Register, awnser);
		return awnser[1];
	}
	
	void writeRegister(Reg a, byte value) {
		writeRegister((byte)a, value);
	}
	
	void writeRegister(byte registerAddress, byte value) override {
		byte send[] = {registerAddress, value};
		spi.write_and_read(sda, 2, send, nullptr);
	}
	
	void setRegisterMask(Reg a, byte value){
		setRegisterMask((byte)a, value);
	}
	
	void setRegisterMask(byte registerAddress, byte value)  override  {
		byte current = readRegister(registerAddress);
		writeRegister(registerAddress, current | value);
	}
	
	void clearRegisterMask(Reg a, byte value){
		clearRegisterMask((byte)a, value);
	}
	
	void clearRegisterMask(byte registerAddress, byte value) override {
		byte current = readRegister(registerAddress);
		writeRegister(registerAddress, current & (~value));
	}
	
	byte getAntennaGain(void) override {
		return readRegister(Reg::RFCfgReg) & (0x07 << 4);
	}
	
	void setAntennaGain(byte value) override {
		if(getAntennaGain() != value){
			clearRegisterMask(Reg::RFCfgReg, (0x07<<4));
			setRegisterMask(Reg::RFCfgReg, value & (0x07<<4));
		}
	}

	
	void antennaOn(void) override {
		byte status = readRegister(Reg::TxControlReg);
		if((status & 0x03) != 0x03){
			writeRegister(Reg::TxControlReg, status | 0x03);
		}
	}
	
	void antennaOff(void) override {
		clearRegisterMask(Reg::TxControlReg, 0x03);
	}
	
	void checkErroAndIrq (byte * result) override {
		result[0] = readRegister(Reg::ComIrqReg);
		result[1] = readRegister(Reg::ErrorReg);
	}
	
	byte readFIFO(void) override  {
		int output_size = (int)readRegister(Reg::FIFOLevelReg);
		
		if (output_size == 0){
			hwlib::cout << "The FIFO buffer is empty";
			return 0;
		}
		return readRegister(Reg::FIFODataReg);
	}
	
	int readFIFO(byte * output) override {
		
		int output_size = (int)readRegister(Reg::FIFOLevelReg);
		
		if (output_size == 0){
			hwlib::cout << "The FIFO buffer is empty";
			return 0;
		}
		
		for (int i = 0; i < output_size; i++){
			output[i] = readRegister(Reg::FIFODataReg);
		}
		
		return output_size;
	}
	
	bool writeFIFO(const byte value) override {
		
		if ((int)readRegister(Reg::FIFOLevelReg) == 64){
			hwlib::cout << "Cannot Write the fifo buffer is full \n";
			return false;
		}
		
		writeRegister(Reg::FIFODataReg, value);
		return true;
	}
	
	bool writeFIFO(const int byte_amount, const byte * data) override {
		
		if (byte_amount > 64){
			hwlib::cout << "The FIFO buffer has a maximum size of 64" << '\n';
			return false;
		}
		
		if((int)readRegister(Reg::FIFOLevelReg) + byte_amount > 64){
			hwlib::cout << "Overflow warning. \n Writing to much data. \n the FIFO-buffer has " 
						<< 64 - (int)readRegister(Reg::FIFOLevelReg) << "byte(s) of space left to write to \n";
			return false;
		}
		
		for(int i = 0; i < byte_amount; i++){
			writeRegister(Reg::FIFODataReg, data[i]);
		}
		return true;
	}
	
	void selfTest(void) override {
		hwlib::cout << "Initializing selftest" << '\n';
		
		byte empty25[25] = {};
		byte result[64];
		
		
		hwlib::cout << "Resetting FIFO buffer" << '\n';
		writeRegister(Reg::FIFOLevelReg, 0x80); //flushes the FIFO buffer.
		
		hwlib::cout << "Resetting chip" << '\n';
		writeRegister(Reg::CommandReg , (byte)CMD::SoftReset);
		hwlib::wait_ms(5000);
		
		hwlib::cout << "Writing 25 empty bytes to internal memory" << '\n';
		writeFIFO(25, empty25);
		writeRegister(Reg::CommandReg, (byte)CMD::Mem);
 
		hwlib::cout << "Setting registers for selftest" << '\n';
		writeRegister(Reg::AutoTestReg, 0x09); //Initializes the selftest to run on the CalcCRC command.
		
		hwlib::cout << "Writing final empty byte FIFO" << '\n';
		writeFIFO(1, 0x00);
		
		hwlib::cout << "Running selftest" << '\n';
		writeRegister(Reg::CommandReg, (byte)CMD::CalcCRC);
		hwlib::wait_ms(2000);
		writeRegister(Reg::CommandReg, (byte)CMD::Idle);
		writeRegister(Reg::AutoTestReg, 0x00);
		
		hwlib::cout << "Test results:" << '\n';
		int n = readFIFO(result);
		
		for (int i = 0; i < n; i++){
			if(i % 8 == 0){
				hwlib::cout << '\n';
			}
			hwlib::cout << hwlib::hex << hwlib::setw(2) << hwlib::setfill('0') << (int)result[i] << ' ';
		}
		hwlib::cout << '\n';
	}
	
	void initChip(void) override {
		if( ! reset.get()){
			reset.set(1);
		} else {
			writeRegister(Reg::CommandReg, (byte)CMD::SoftReset);
			hwlib::wait_ms(100);
		}
		
		writeRegister(Reg::TmodeReg, 0x80);
		writeRegister(Reg::TPrescalerReg, 0x9A);
		writeRegister(Reg::TReloadRegH, 0x03);
		writeRegister(Reg::TreloadRegL, 0xE8);
		writeRegister(Reg::TxASKreg, 0x40);
		writeRegister(Reg::ModeReg, 0x3D);
		antennaOn();
		setAntennaGain(0x70);
	}
	
	bool trancieveData(const byte * data_in,
				   const int data_in_lenght, 
				   byte * data_out, 
				   int * data_out_lenght, 
				   bool crc = false, 
				   bool Bitwraping = false) override {
		return communicateNFC(data_in, data_in_lenght, CMD::Trancieve, data_out, data_out_lenght, crc, Bitwraping);
	}
	
	bool authentCard(const byte * data_in, const int data_in_lenght) override {
		byte dummy[64];
		return communicateNFC(data_in, data_in_lenght, CMD::MFAuthent, dummy, nullptr, false, false);
	}
	
	bool communicateNFC(const byte * data_in,
					 const int data_in_lenght, 
					 CMD command, 
					 byte * data_out, 
					 int * data_out_lenght, 
					 bool crc = false, 
					 bool Bitwraping = false) {
						
		return communicateNFC(data_in, data_in_lenght, (byte)command, data_out, data_out_lenght, crc, Bitwraping);
		}
	
	bool communicateNFC(const byte * data_in,
					 const int data_in_lenght, 
					 byte command, 
					 byte * data_out, 
					 int * data_out_lenght, 
					 bool crc = false, 
					 bool Bitwraping = false) override {
		byte crcresult[2];
		bool validdata = false;
		
		writeRegister(Reg::CommandReg, (byte)CMD::Idle);
		writeRegister(Reg::ComIrqReg, 0x7F);
		setRegisterMask(Reg::FIFOLevelReg, 0x80);
		if (Bitwraping == true){
			writeRegister(Reg::BitFramingReg, 0x07);
		} else {
			writeRegister(Reg::BitFramingReg, 0x00);
		}
		
		if (data_in_lenght == 1){
			if (crc == true){
				if ((data_in_lenght + (int)readRegister(Reg::FIFOLevelReg)) > 62){
					hwlib::cout << "Writing to much data to add CRC calculation results\n CRC results need TWO bytes of room to be added\n"; 
					return false;
				}
				calculateCRC(data_in, data_in_lenght, crcresult);
				writeFIFO(*data_in);
				writeFIFO(2, crcresult);
			} else {
				writeFIFO(*data_in);
			}
		} else {
			if (crc == true){
				if ((data_in_lenght + (int)readRegister(Reg::FIFOLevelReg)) > 62){
					hwlib::cout << "Writing to much data to add CRC calculation results\n CRC results need TWO bytes of room to be added\n"; 
					return false;
				}
				calculateCRC(data_in, data_in_lenght, crcresult);
				writeFIFO(data_in_lenght, data_in);
				writeFIFO(2, crcresult);
			} else {
				writeFIFO(data_in_lenght, data_in);
			}
		}
		writeRegister(Reg::CommandReg, command);
		if(command == (byte)CMD::Trancieve){
			setRegisterMask(Reg::BitFramingReg, 0x80);
		}
		
		int waittime = 2000;
		while(! validdata){
			byte n = readRegister(Reg::ComIrqReg);
			if (n & 0x30){
				validdata = true;
			}
			
			if (n & 0x01){
				hwlib::cout << "timer interupt \n";
				return false;
			}
			
			if (--waittime == 0){
				hwlib::cout << "general timeout";
				if ((int)readRegister(Reg::FIFOLevelReg) >= 0){
					hwlib::cout << "No data in Fifo buffer";
					return false;
				}
			}
		}
		
		byte error = readRegister(Reg::ErrorReg);
		
		if(error & 0x13){
			hwlib::cout << "Buffer Pairity or Protocol error";
			return false;
		}
		if (command != (byte)CMD::MFAuthent){
			hwlib::wait_ms(50);
			if (data_out_lenght == nullptr){
				readFIFO(data_out);
			} else {
				*data_out_lenght = readFIFO(data_out);
			}
		}
		
		return true;
	}
					 
	bool isCard (byte * cardtype) override {
		hwlib::cout << "Function requires protocol decoration to be used\n";
		return false;
	}
	
	bool selectCard(byte * Cardserial) override {
		hwlib::cout << "Function requires protocol decoration to be used\n";
		return false;
	}
	
	bool authenticateSector(byte typekey, byte * block_address, byte * key, byte * Cardserial) override {
		hwlib::cout << "Function requires protocol decoration to be used\n";
		return false;
	}
	
	
	bool readBlock(byte block_address, byte * data_out) override {
		hwlib::cout << "Function requires protocol decoration to be used\n";
		return false;
	}
	
	bool readSector(const int sectorsize, 
					byte (*sector_out)[16], 
					byte typekey, 
					byte * first_block_in_sector, 
					byte * key, 
					byte * Cardserial){
		hwlib::cout << "Function requires protocol decoration to be used\n";
		return false;
	}
	
	bool writeBlock(const byte block_address,const byte * data_in,const int lenght) override {
		hwlib::cout << "Function requires protocol decoration to be used\n";
		return false;
	}
	
	
	bool writeSector(const int sectorsize, 
					 byte (*sector_in)[16], 
					 byte typekey, 
					 byte * first_block_in_sector, 
					 byte * key, 
					 byte * Cardserial){
		hwlib::cout << "Function requires protocol decoration to be used\n";
		return false;
	}	
	
	
	int calculateCRC(const byte * data, const int length, byte * result) override {
		
		writeRegister(Reg::CommandReg, (byte)CMD::Idle);
		writeRegister(Reg::DivIrqReg, 0x04);
		setRegisterMask(Reg::FIFOLevelReg, 0x80);
		if (length == 1){
			writeFIFO(*data);
		} else {
			writeFIFO(length, data);
		}
		writeRegister(Reg::CommandReg, (byte)CMD::CalcCRC);
		
		int i = 2000;
		byte n;
		
		while(1){
			n = readRegister(Reg::DivIrqReg);
			if(n & 0x04){
				break;
			}
			if(--i == 0){
				return 1;
			}
		}
	writeRegister(Reg::CommandReg, (byte)CMD::Idle);
	
	result[0] = readRegister(Reg::CRCResultL);
	result[1] = readRegister(Reg::CRCResultH);
	return 0;
	}
/// \endcodn
};
#endif // RC522_HPP
