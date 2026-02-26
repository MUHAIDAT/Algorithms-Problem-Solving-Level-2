#include <iostream>
using namespace std;
int ReadPosativeNumber(string message)
{
	int Number = 0;
	do
	{
		cout << message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;

}
void  EnterArray(int arr[] ,int NumberOfArray)
{
	cout << "Enter Array Element: " << endl;
	for (int i = 0; i < NumberOfArray; i++)
	{
		cout << "Elememt[" << i << "] : ";
		cin >>  arr[i];
	}
}
int EnterCheckNumber()
{
	int CheckNumber;
	cout << "Enter the number tou want to check: ";
	cin >> CheckNumber;
	cout << "." << endl;
	return CheckNumber;
}
void PrintArray(int arr[], int NumberOfArray)
{
	cout << "Original Array : ";
	for (int i = 0; i < NumberOfArray ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int CheckOfNumber(int arr[], int CheckNumber, int NumberOfArray)
{
	
	int Counter = 0;
	for (int i = 0; i < NumberOfArray -1; i++)
	{
		if (arr[i] == CheckNumber)
		Counter++;
	}
	return Counter;
}
void PrintCountOfNumber(int Counter , int CheckNumber)
{
	cout << CheckNumber << " is repeated " << Counter << "time(s)." << endl;
}
int main()
{
	int NumberOfArray = ReadPosativeNumber("Enter how many elements you want in the array: ");
	int arr[100];
	EnterArray(arr, NumberOfArray);
	int CheckNumber = EnterCheckNumber();
	PrintArray(arr, NumberOfArray);
	int Counter = CheckOfNumber(arr, NumberOfArray, CheckNumber);
	PrintCountOfNumber(Counter, CheckNumber);

	return 0;
}