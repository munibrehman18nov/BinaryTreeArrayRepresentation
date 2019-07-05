#ifndef NOTALLOWED_H
#define NOTALLOWED_H
#include<iostream>
using namespace std;

class NotAllowed //:public exception
{
	char *msg;
public:
	NotAllowed(char *);
	void printMsg();
};

#endif