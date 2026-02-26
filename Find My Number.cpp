#include<iostream>
using namespace std;

int RandomNumber(int To, int From)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FullArrayWithRandomNumber(int arr[100], int& arrLength)
{
	cout << "Enter number of elements\n";
	cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{

		arr[i] = RandomNumber(1, 100);
	}
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int ReadNumber()
{
	int Number;
	cout << "\nPlease enter a number to search for?\n";
	cin >> Number;
	return Number;
}
int FindNumberPositionInArray(int arr[100], int arrLength, int Number)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;
	}
	return -1;
}
bool IsNumberInArray(int arr[100], int arrLength, int Number)
{
	return FindNumberPositionInArray(arr, arrLength, Number) != -1;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int arrLength;

	FullArrayWithRandomNumber(arr, arrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);
	int Number = ReadNumber();
	
	cout << "\nNumber you are looking for is: " << Number << endl;

	if (!IsNumberInArray(arr, arrLength, Number))
	{
		cout << "No, The number is not found :-(\n";
	}
	else
	{
		cout << "Yes it is found :-)\n";
	}
	return 0;
}