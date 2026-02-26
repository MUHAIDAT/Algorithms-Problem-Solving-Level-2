#include <iostream>
using namespace std;

int ReadpositiveNumber(string Message)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;
	} while (Number < 0);
	
	return Number;
}
void FillArray(int arr[100], int &arrLength) // Fixed parameter type to array
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << "[" << i + 1 << "] = ";
		cin >> arr[i];
	}
}
void PrintArray(int arr[], int arrLength) // Fixed parameter type to array
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
bool IsPalindrome(int arr[], int arrLength) // Fixed parameter type to array
{
	for (int i = 0; i < arrLength / 2; i++)
	{
		if (arr[i] != arr[arrLength - i - 1]) // Fixed logical error and syntax
			return false;
	}
	return true;
}

int main()
{
	int arrLength = ReadpositiveNumber("Enter a positive numner?");
	int arr[100];

	FillArray(arr, arrLength);

	PrintArray(arr, arrLength);

	if (IsPalindrome(arr, arrLength))
		cout << "The array is a palindrome." << endl;
	else
		cout << "The array is not a palindrome ." << endl;
	return 0;
}
