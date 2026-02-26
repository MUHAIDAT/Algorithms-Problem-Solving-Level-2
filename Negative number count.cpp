#include<iostream>
using namespace std;
int ReadPositiveNumber(string message)
{
	int Number;
	do
	{
		cout << message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(-100, 100);
	}
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int CountNegativeNumber(int arr[100], int arrLength)
{
	int NegativeNum = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] < 0)
			NegativeNum++;
	}
	return NegativeNum;
}
int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int arrLength = ReadPositiveNumber("Enter number of element: ");

	FillArrayWithRandomNumbers(arr, arrLength);

	cout << "\nArray Elements: ";
	PrintArray(arr, arrLength);

	cout << "\nNegative Numbers count is: ";
	cout << CountNegativeNumber(arr, arrLength) << endl;
	return 0;


}