#include<iostream>
#include<string>
using namespace std;

int ReadPositiveNumber(string message)
{
	int Number = 0;

	do
	{
		cout << message << endl;
		cin >> Number;

	} while (Number < 0);


	return Number;
}
int CountDigitFrequency(short DigiteToCheck, int Number)
{
	int Remainder = 0;
	int FreqCount = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		if (Remainder == DigiteToCheck)
		{
			FreqCount++;
		}
	}
	return FreqCount;
}
int main()
{
	int Number = ReadPositiveNumber("Please enter a positive number: ");
	short DigiteToCheck = ReadPositiveNumber("Please enter a single digit to count: ");
	cout << "Digite " << DigiteToCheck << " Frequency is " << CountDigitFrequency(DigiteToCheck, Number) << " Times.";
	return 0;
}