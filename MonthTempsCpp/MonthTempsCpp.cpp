// MonthTempsCpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//



#include "pch.h"
#include <string>
#include <iostream>
using namespace std;

#define HIGH_T 0
#define LOW_T 1

string monthNames[12] = { "January","February","March","April","May","June",
						  "July","August","September","October","November","December" };


void GetInput(int monthTemps[12][2])
{
	int monthCount = 0;
	int tempCount;

	int inputTemp;

	string highLowPrompt;

	string inputStr;

	cout << "Input Temperature Data:" << endl;
	cout << "(High then Low for all 12 months, starting with January)" << endl;
	while (monthCount < 12)
	{
		tempCount = 0;
		cout << monthNames[monthCount] << endl;
		while (tempCount < 2)
		{
			highLowPrompt = (tempCount == 0) ? "High" : "Low";
			cout << highLowPrompt << endl;

			getline(cin, inputStr);
			inputTemp = stoi(inputStr);
			monthTemps[monthCount][tempCount] = inputTemp;

			tempCount++;
		}
		monthCount++;
	}
}

float AverageTemp(int monthTemps[12][2], int hi_lo)
{
	int total = 0;
	for (int i = 0; i < 12; i++)
	{
		total += monthTemps[i][hi_lo];
	}
	float avg = total / 12;
	return avg;
}

int IndexTemp(int monthTemps[12][2], int hi_lo)
{
	int bestTemp = (hi_lo == HIGH_T) ? -9999 : 9999;
	int bestIndex = 13;
	for (int i = 0; i < 12; i++)
	{
		if ((hi_lo == HIGH_T && monthTemps[i][HIGH_T] > bestTemp) ||
			(hi_lo == LOW_T && monthTemps[i][LOW_T] < bestTemp))
		{
			bestTemp = monthTemps[i][hi_lo];
			bestIndex = i;
		}
	}
	return bestIndex;
}

int main()
{
	std::cout << "Hello World!\n";
	while (true)
	{
		int monthTemps[12][2];
		GetInput(monthTemps);

		cout << "--------------------" << endl;
		for (int i = 0; i < 12; i++)
		{
			cout << monthNames[i] << ": " << monthTemps[i][0] << "\370 H, " << monthTemps[i][1] << "\370 L" << endl;
		}
		cout << "--------------------" << endl;
		float avgHi = AverageTemp(monthTemps,HIGH_T);
		float avgLo = AverageTemp(monthTemps,LOW_T);
		cout << "Average High: " << avgHi << "\370" << endl;
		cout << "Average Low: " << avgLo << "\370" << endl;
		cout << "--------------------" << endl;
		int hiIndex = IndexTemp(monthTemps, HIGH_T);
		int loIndex = IndexTemp(monthTemps, LOW_T);

		cout << "Highest High: " << endl;
		cout << monthNames[hiIndex] << " - " << monthTemps[hiIndex][0] << "\370" << endl;
		cout << "Lowest Low: " << endl;
		cout << monthNames[loIndex] << " - " << monthTemps[loIndex][1] << "\370" << endl;
		cout << "--------------------" << endl;
		cout << "Done!" << endl;
		
		break;
	}

}

