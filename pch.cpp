// pch.cpp: source file corresponding to pre-compiled header; necessary for compilation to succeed

#include "pch.h"
#include <string>
#include <iostream>

Crypter::Crypter()
{
	
}



void Crypter::GetBinari(int n, int b[])
{
	
	int i =7;
	while (n > 0)
	{
		b[i] = n % 2;
		n = n / 2;
		i--;
	}

}
void Crypter::ComplementOne(int b[])
{
	for (int i = 0; i < 8; i++)
	{
		if (b[i] == 1)
		{
			b[i] = 0;
		}
		else 
		{
			b[i] = 1;
		}
	}
}

void Crypter::Reverse(int b[]) 
{
	int temp;
	for (int i = 0; i < 4; i++)
	{
		temp = b[i];
		b[i] = b[7 - i];
		b[7 - i] = temp;
	}
}

int Crypter::GetInteger(int b[])
{
	int result = 0;
	int cp = 1;
	for (int i = 7; i > -1; i--)
	{
		result += cp * b[i];
		cp *= 2;
	}
	return result;
}


