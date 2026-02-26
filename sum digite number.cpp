#include <iostream>
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
int SumOfDigite(int Number)
{
	int Sum = 0;
	int Remainder = 0;
	while (Number > 0)
	{
		Remainder = Number % 10;
		Number /= 10;
		Sum += Remainder;
		
	}
	return Sum;
}
int main ()
{
	cout << "sum of digite = " << SumOfDigite(ReadPositiveNumber("Please enter a positive number?")) << endl;

	

	return 0;
	
	
	
}
