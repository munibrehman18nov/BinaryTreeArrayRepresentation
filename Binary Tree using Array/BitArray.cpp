#include "bitArray.h"
#include<iostream>
using namespace std;

BitArray::BitArray(const BitArray & ref)
{
	capacity = ref.capacity;
	int s = (int)ceil((float)capacity / 8);
	data = new unsigned char[s];
	for (int i = 0; i < s; i++)
	{
		data[i] = ref.data[i];
	}
}
BitArray::BitArray(int n)
{
	capacity = n;
	int s = (int)ceil((float)capacity / 8);
	data = new unsigned char[s];
	for (int i = 0; i < s; i++)
	{
		data[i] = data[i] & 0;
	}
}
void BitArray::on(int bitNo)
{
	unsigned char ch = 1;
	int s = (int)ceil((float)capacity / 8) - 1, i = s - (bitNo / 8);
	ch = ch << (bitNo % 8);
	data[i] = data[i] | ch;
}
void BitArray::off(int bitNo)
{
	unsigned char ch = 1;
	int s = (int)ceil((float)capacity / 8) - 1, i = s - (bitNo / 8);
	ch = ch << (bitNo % 8);
	ch = ~ch;
	data[i] = data[i] & ch;
}
int BitArray::checkBitStatus(int bitNo)
{
	unsigned char ch = 1;
	int s = (int)ceil((float)capacity / 8) - 1, i = s - (bitNo / 8);
	ch = ch << (bitNo % 8);
	if ((ch & data[i]) == ch)
		return 1;
	else
		return 0;
}
void BitArray::invert(int bitNo)
{
	if (checkBitStatus(bitNo))
		off(bitNo);
	else
		on(bitNo);
}
void BitArray::dump()
{
	for (int i = capacity - 1; i >= 0; i--)
	{
		if ((i + 1) % 8 == 0 && i != (capacity - 1))
			cout << " ";
		if (checkBitStatus(i))
			cout << "1";
		else
			cout << "0";
	}
	cout << "\n";
}
BitArray BitArray::AND(BitArray & ref)
{
	BitArray result(capacity);
	for (int i = 0; i < capacity; i++)
	{
		if ((checkBitStatus(i)) && (ref.checkBitStatus(i)))
			result.on(i);
		else
			result.off(i);
	}
	//result.dump();
	return result;
}
BitArray BitArray::OR(BitArray & ref)
{
	BitArray result(capacity);
	for (int i = 0; i < capacity; i++)
	{
		if ((checkBitStatus(i)) || (ref.checkBitStatus(i)))
			result.on(i);
		else
			result.off(i);
	}
	//result.dump();
	return result;
}
