#include<iostream>
using namespace std;
enum enPrimeNotPrime {IsPrime = 1,NotPrime = 2};
enPrimeNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int counter = 2; counter <= M; counter++)
	{
		if (Number % counter == 0)
			return enPrimeNotPrime::NotPrime;
	}
	return enPrimeNotPrime::IsPrime;

}
int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{
	cout << "Enter Number for element: \n";
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
	cout << " ";
}
void AddArrayElement(int Number, int arr[100], int& arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}
void CopyPrimeNumbers(int arrSource[100], int arrDestination[100], int arrLength, int& arrDestinationLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimeNotPrime::IsPrime)
		{
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
		}
	}
}


int main()
{
	int arr[100];
	int arrLength = 0;

	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100];
	int arr2Length = 0;

	CopyPrimeNumbers(arr, arr2, arrLength, arr2Length);

	cout << "array Element: \n";
	PrintArray(arr, arrLength);

	cout << "\n\nCopy prime array: \n";
	PrintArray(arr2, arr2Length);


	return 0;
}