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
void PrintInvertedLetterPattern(int Number)
{
	for (int i = 65 + Number - 1; i >= 65; i--)
	{
		int count = Number - (65 + Number - 1 - i);
		for (int j = 1; j <= count; j++)
		{
			cout << char(i);
		}
		cout << endl;
	}
}
int main()
{
	PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positiv number? "));
	return 0;
}