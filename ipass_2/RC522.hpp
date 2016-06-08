#ifndef RC522_HPP
#define RC522_HPP

#include "hwlib.hpp"
#include "nfccontroler.hpp"

class RC522
{
private:

	hwlib::pin_out & sda;
	hwlib::pin_in_out & reset;
	hwlib::spi_bus & spi;
	
	
public:
	
	RC522(hwlib::pin_out & sda, hwlib::pin_in_out & reset, hwlib::spi_bus & spi):
	sda(sda), reset(reset), spi(spi)
	{}
	
	enum Keytype{
		// The 2 types of keys you can authenticate with.
		AuthwithA	= 0x60, // Starts authentication with key A.
		AuthwithB	= 0x61  // Starts authentication with key B.
	};
	
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
		SoftReset	= 0x0F, // Resets the MFRC522.
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
		BitFramingReg	= 0x0D << 1,// Adjustments for bit oriented frames.
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
	
	void setRegisterMask(Reg a, byte value){
		byte current = readRegister(a);
		writeRegister(a, current | value);
	}
	
	void clearRegisterMask(Reg a, byte value){
		byte current = readRegister(a);
		writeRegister(a, current & (~value));
	}
	
	byte getAntennaGain(void){
		return readRegister(RFCfgReg) & (0x07 << 4);
	}
	
	void setAntennaGain(byte value){
		if(getAntennaGain() != value){
			clearRegisterMask(RFCfgReg, (0x07<<4));
			setRegisterMask(RFCfgReg, value & (0x07<<4));
		}
	}

	
	void antennaOn(void){
		byte status = readRegister(TxControlReg);
		if((status & 0x03) != 0x03){
			writeRegister(TxControlReg, status | 0x03);
		}
	}
	
	void antennaOff(void){
		clearRegisterMask(TxControlReg, 0x03);
	}
	
	int readFIFO(void){
		int output_size = (int)readRegister(FIFOLevelReg);
		
		if (output_size == 0){
			hwlib::cout << "The FIFO buffer is empty";
			return 0;
		}
		return (int)readRegister(FIFODataReg);
	}
	
	int readFIFO(byte * output){
		
		int output_size = (int)readRegister(FIFOLevelReg);
		
		//hwlib::cout << output_size; // debug
		
		if (output_size == 0){
			hwlib::cout << "The FIFO buffer is empty";
			return 0;
		}
		
		for (int i = 0; i < output_size; i++){
			output[i] = readRegister(FIFODataReg);
			//hwlib::cout << hwlib::hex << hwlib::setw(2) << hwlib::setfill('0') << (int)output[i];
		}
		
		return output_size;
	}
	
	int writeFIFO(const byte value){
		
		if ((int)readRegister(FIFOLevelReg) == 64){
			hwlib::cout << "Cannot Write the fifo buffer is full \n";
		}
		
		writeRegister(FIFODataReg, value);
		return 0;
	}
	
	int writeFIFO(const int byte_amount, const byte * data){
		
		if (byte_amount > 64){
			hwlib::cout << "The FIFO buffer has a maximum size of 64" << '\n';
			return 1;
		}
		
		if((int)readRegister(FIFOLevelReg) + byte_amount > 64){
			hwlib::cout << "Overflow warning. \n Writing to much data. \n the FIFO-buffer has " 
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
		byte result[64];
		
		
		hwlib::cout << "Resetting FIFO buffer" << '\n';
		writeRegister(FIFOLevelReg, 0x80); //flushes the FIFO buffer.
		
		hwlib::cout << "Resetting chip" << '\n';
		writeRegister(CommandReg , SoftReset);
		hwlib::wait_ms(5000);
		
		hwlib::cout << "Writing 25 empty bytes to internal memory" << '\n';
		writeFIFO(25, empty25);
		writeRegister(CommandReg, Mem);
 
		hwlib::cout << "Setting registers for selftest" << '\n';
		writeRegister(AutoTestReg, 0x09); //Initializes the selftest to run on the CalcCRC command.
		
		hwlib::cout << "Writing final empty byte FIFO" << '\n';
		writeFIFO(1, 0x00);
		
		hwlib::cout << "Running selftest" << '\n';
		writeRegister(CommandReg, CalcCRC);
		hwlib::wait_ms(2000);
		writeRegister(CommandReg, Idle);
		writeRegister(AutoTestReg, 0x00);
		
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
	
	void init_chip(void){
		if( ! reset.get()){
			reset.set(1);
		} else {
			writeRegister(CommandReg, SoftReset);
			hwlib::wait_ms(100);
		}
		
		writeRegister(TmodeReg, 0x80);
		writeRegister(TPrescalerReg, 0x9A);
		writeRegister(TReloadRegH, 0x03);
		writeRegister(TreloadRegL, 0xE8);
		writeRegister(TxASKreg, 0x40);
		writeRegister(ModeReg, 0x3D);
		antennaOn();
		setAntennaGain(0x70);
	}
	
	bool communicate(const byte * data_in,
					 const int data_in_lenght, 
					 CMD command, 
					 byte * data_out, 
					 int * data_out_lenght, 
					 bool crc = false, 
					 bool REQA = false){
						 
		byte crcresult[2];
		bool validdata = false;
		
		writeRegister(CommandReg, Idle);
		writeRegister(ComIrqReg, 0x7F);
		setRegisterMask(FIFOLevelReg, 0x80);
		if (REQA == true){
			writeRegister(BitFramingReg, 0x07);
		} else {
			writeRegister(BitFramingReg, 0x00);
		}
		
		if (data_in_lenght == 1){
			if (crc == true){
				calculateCRC(data_in, data_in_lenght, crcresult);
				writeFIFO(*data_in);
				writeFIFO(2, crcresult);
			} else {
				writeFIFO(*data_in);
			}
		} else {
			if (crc == true){
				calculateCRC(data_in, data_in_lenght, crcresult);
				writeFIFO(data_in_lenght, data_in);
				writeFIFO(2, crcresult);
			} else {
				writeFIFO(data_in_lenght, data_in);
			}
		}
		writeRegister(CommandReg, command);
		if(command == Trancieve){
			setRegisterMask(BitFramingReg, 0x80);
		}
		
		int waittime = 2000;
		while(! validdata){
			byte n = readRegister(ComIrqReg);
			if (n & 0x30){
				validdata = true;
				//hwlib::cout << "valid data recieved\n";
				//hwlib::cout << hwlib::hex << hwlib::setw(2) << hwlib::setfill('0') << (int)readRegister(FIFODataReg) << (int)readRegister(FIFODataReg);
			}
			if (n & 0x01){
				hwlib::cout << "timer interupt \n";
				return false;
			}
			if (--waittime == 0){
				hwlib::cout << "general timeout";
				if ((int)readRegister(FIFOLevelReg) >= 0){
					hwlib::cout << "No data in Fifo buffer";
					return false;
				}
			}
		}
		
		byte error = readRegister(ErrorReg);
		
		if(error & 0x13){
			hwlib::cout << "Buffer Pairity or Protocol error";
			return false;
		}
		if (command != MFAuthent){
			
			if (data_out_lenght == nullptr){
				readFIFO(data_out);
			} else {
				*data_out_lenght = readFIFO(data_out);
			}
		}
		
		return true;
	}
	
	bool iscard (byte * cardtype){
		byte reqa = 0x26;
		bool card = false;
		while(card == false){
			hwlib::wait_ms(333);
			card = communicate(&reqa, 1, Trancieve, cardtype, nullptr, false, true);
		}
		return true;
	}
	
	bool select_card(byte * Cardserial){
		
		byte Get_UID[2] =  {0x93, 0x20};
		byte Sel_card[7] = {0x93, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00};
		byte UID[5];
		byte Sak[3];
		byte CRCcheck[2];
		int SAK_size;
		int UID_lenght;
		
		communicate(Get_UID, 2, Trancieve, UID, &UID_lenght, false, false);
		
		byte CRC_A = UID[0] ^ UID[1] ^ UID[2] ^ UID[3];
		if (UID[4] != CRC_A){
			hwlib::cout << "Could not select card. UID-CRC does not match expected.\n";
			return false;
		}
		
		hwlib::wait_ms(333);
		
		for(int i = 0; i < 5; i++){
			Sel_card[i + 2] = UID[i];
		}
		
		
		communicate(Sel_card, 7, Trancieve, Sak, &SAK_size, true, false);
		
		calculateCRC(&Sak[0], 1, CRCcheck);
		
		if(Sak[0] == 0x08){
			if((Sak[1] != CRCcheck[0]) || (Sak[2] != CRCcheck[1])){
				hwlib::cout << "Selection error. Sak CRC does not match expected";
			return false;
			}
			
		} else {
			hwlib::cout << "No valid SAK response";
			return false;
		}
		
		for(int i = 0; i < 4; i++){
			Cardserial[i] = UID[i];
		}
		hwlib::cout << "Card selected\n";
		return true;
	}
	
	bool authenticate_classic(Keytype typekey, byte * block_address, byte * key, byte * Cardserial){
		int n = 2;
		byte auth[12];
		byte dummy[64];
		
		auth[0] = typekey;
		auth[1] = *block_address;
		
		for(int i = 0; i < 6; i++ ){
			auth[n] = key[i];
			n++;
		}
		
		for(int i = 0; i < 4; i++){
			auth[n] = Cardserial[i];
			n++;
		}
		
		if (n > 13){
			hwlib::cout << "Authentication error, to much data\n";
			return false;
		}
		
		communicate(auth, 12, MFAuthent, dummy, nullptr, false, false);
		
		if((readRegister(ComIrqReg) == 0x14) && (readRegister(ErrorReg) == 0x00)){
			hwlib::cout << "Authentication Successfull\n";
			return true;
		} else {
			hwlib::cout << "Authentication Unsuccessfull\n";
			return false;
		}
		
		//hwlib::cout << hwlib::hex << hwlib::setw(2) << hwlib::setfill('0') << (int)readRegister(ComIrqReg)<< ' ' << (int)readRegister(ErrorReg);
		return true;
	}
	
	bool readblock(byte block_address, byte * data_out){
		byte read[2] = {0x30, block_address};
		byte Intermediate[18];
		byte data_crc[2];
		byte check_crc[2];
		byte data[16];
		
		communicate(read, 2, Trancieve, Intermediate, nullptr, true, false);
		
		for (int i = 0; i < 16; i++){
			data[i] = Intermediate[i];
		}
		
		for (int i = 0; i < 2; i++){
			data_crc[i] = Intermediate[i + 16];
		}
		
		calculateCRC(data, 16, check_crc);
		
		/*hwlib::cout << hwlib::hex << hwlib::setw(2) << hwlib::setfill('0') << (int)data_crc[0]<< ' ' << (int)data_crc[1] << '\n';
		hwlib::cout << hwlib::hex << hwlib::setw(2) << hwlib::setfill('0') << (int)check_crc[0]<< ' ' << (int)check_crc[1];*/
		
		for (int i = 0; i < 2; i++){
			if(data_crc[i] != check_crc[i]){
				hwlib::cout << "CRC of recieved data does not match\n";
				return false;
			}
		}
		
		for (int i = 0; i < 16; i++){
			data_out[i] = data[i];
		}
		
		return true;
	}
	
	bool writeBlock(const byte block_address,const byte * data_in,const int lenght){
		byte read[2] = {0xA0, block_address};
		byte Ack, Ack2;
		byte appended_data[16] = {};
		
		communicate(read, 2, Trancieve, &Ack, nullptr, true, false);
		
		if (Ack != 0x0A){
		
			hwlib::cout << "Write error did not recieve acknowledge after selecting the block to be written to.\n";
			return false;
		}
		
		if ( lenght < 16){
			
			for (int i = 0; i < lenght; i++){
				appended_data[i] = data_in[i];
			}
		}
		
		communicate(appended_data, 16, Trancieve, &Ack2, nullptr, true, false);
		
		
		if (Ack != 0x0A){
		
			hwlib::cout << "Write error did not recieve acknowledge after the data was written.\n";
			return false;
		}
		
		return true;
	}
	
	
	
	int calculateCRC(const byte * data, const int length, byte * result){
		
		writeRegister(CommandReg, Idle);
		writeRegister(DivIrqReg, 0x04);
		setRegisterMask(FIFOLevelReg, 0x80);
		if (length == 1){
			writeFIFO(*data);
		} else {
			writeFIFO(length, data);
		}
		writeRegister(CommandReg, CalcCRC);
		
		int i = 2000;
		byte n;
		
		while(1){
			n = readRegister(DivIrqReg);
			if(n & 0x04){
				break;
			}
			if(--i == 0){
				return 1;
			}
		}
	writeRegister(CommandReg, Idle);
	
	result[0] = readRegister(CRCResultL);
	result[1] = readRegister(CRCResultH);
	return 0;
	}
	
	
};



#endif // RC522_HPP
