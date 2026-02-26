#include < iostream>
#include < string>
using namespace std;

int ReadPositiveNumber(string message)
{
	int Number = 0;
	do
	{

		cout << message << endl;
		cin >> Number;

	} while (Number <= 0);
	return Number;
}
int CountDigitNumber(short DigitOfNumber, int Number)
{
	int Countfreq = 0;
	int Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		if (Remainder == DigitOfNumber)
		{
			Countfreq++;
		}
		
	}
	return Countfreq;
}
void PrintAllDigitsNmber(int Number)
{
	cout << endl;

	for (short i = 1; i <= 9; i++)
	{
		int freq = CountDigitNumber(i, Number);
		if (freq >= 0)
		{
			cout << "Digit " << i << " frequency is " << freq << " time's" <<  endl;

		}
	}
}
int main()
{
	int Number = ReadPositiveNumber("please enter a positive number? ");
	PrintAllDigitsNmber(Number);
	return 0;
}
