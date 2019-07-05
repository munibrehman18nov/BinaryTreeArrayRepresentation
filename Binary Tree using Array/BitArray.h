#ifndef BITARRAY_H
#include<iomanip>
#define BITARRAY_H
class BitArray
{
public:
	int capacity;
	unsigned char * data;
	int isValidBit(int i)
	{
		return i >= 0 && i < capacity;
	}
	BitArray(int n = 8);
	BitArray(const BitArray & ref);
	void on(int);
	void off(int);
	int checkBitStatus(int);
	void invert(int);
	void dump();
	BitArray AND(BitArray & ref);
	BitArray OR(BitArray & ref);
};
#endif