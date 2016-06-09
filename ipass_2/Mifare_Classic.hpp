#ifndef MIFARE_CLASSIC_HPP
#define MIFARE_CLASSIC_HPP
#include "RC522.hpp"

class Mifare_Classic : public RC522
{
private:
	RC522 & slave;
public:
	Mifare_Classic(RC522 & slave):
		slave(slave)
		{}


#endif // MIFARE_CLASSIC_HPP
