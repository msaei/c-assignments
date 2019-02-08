// CryptingAssignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string> // make string class available
#include <fstream>
using namespace std;

int main()
{
	using namespace std;
	string str;
	
	int ac;
	Crypter c1;

	ifstream fin("input.txt");
	ofstream encOut("enc.txt");
	
	
	while (!fin.eof())
	{
		getline(fin, str);
		
		for (int i = 0; i < str.size(); i++)
		{
			ac = int(str[i]);
			int b[8] = { 0,0,0,0,0,0,0,0 };
			c1.GetBinari(ac, b);
			c1.ComplementOne(b);
			c1.Reverse(b);
			for (int i = 0; i < 8; i++)
			{
				cout << b[i];
				encOut << b[i];
			}
			
		}
		
		encOut << "10101111";
		
	}
	encOut.close();
	ifstream encIn("enc.txt");
	ofstream decOut("dec.txt");
	getline(encIn, str);
	//cout << str;
	for (int i = 0; i < str.size(); i += 8)
		{
			int b[8];
			string ss = str.substr(i, 8);
			for (int i = 0; i < 8; i++) {
				b[i] = ss[i] - '0';
			}
			c1.Reverse(b);
			c1.ComplementOne(b);
			int ac = c1.GetInteger(b);
			decOut << char(ac);

		}
	

	return 0;
}



