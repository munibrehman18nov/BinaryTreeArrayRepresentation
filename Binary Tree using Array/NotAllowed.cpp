#include "NotAllowed.h"
#include<iostream>
using namespace std;


NotAllowed::NotAllowed(char*s)
{
	msg = s;
}
void NotAllowed::printMsg()
{
	int i = 0;
	while (msg[i] != '\0')
	{
		cout << msg[i];
		i++;
	}
}

