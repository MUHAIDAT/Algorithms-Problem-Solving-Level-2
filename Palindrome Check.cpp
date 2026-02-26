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
int reveringNumber(int Number)
{
	int Remainder = 0;
	int Number2 = 0;
	while(Number > 0)
	{ 
		Remainder = Number % 10;
		Number = Number / 10;
		Number2 = Number2 * 10 + Remainder;
	}
	return Number2;
}
bool PalindromeCheck(int Number)
{
	return Number == reveringNumber(Number);
}
int main()
{
	if (PalindromeCheck(ReadPositiveNumber("Please enter a positive number?")))
		cout << "Yes,it is a palindrome number.";
	else
		cout << "No,it is NOT a Palindrome number.";
	return 0;
}