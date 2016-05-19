/*#include "RFID_RC522.h"*/
#include "RFC_default_pins"
#include "NfcControler.h"

int main(void)
{
	default_pins p;
	NfcControler & a = p;
	a.blink();
	
	return 0;
}