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

	} while (Number <= 0);


	return Number;
}
void PrintDigite(int Number)
{
	int Remainder = 0;
	int Number2 = 0;

	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Number2 = Number2 * 10 + Remainder;
	}
	cout << "Reverse of Number: " << Number2;
}
int main()
{
	PrintDigite(ReadPositiveNumber("Please enter a positive number: "));
	return 0;
}