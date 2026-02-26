#include<iostream>
#include<string>
using namespace std;

int RandNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
int ReadPositiveNumber(string Message)
{
	int Number;
	do
	{
		cout << Message << endl;
		cin >> Number;
	} while (Number < 0);
	return Number;
}
void FillArrayWithRandomNumbers(int arr[100], int arrlongth)
{
	for (int i = 0; i < arrlongth; i++)
	{
		arr[i] = RandNumber(1, 100);
	}
}
void SumOf2Arrays(int arr[100], int arrlongth , int arr2[100], int arrSum[100])
{
	for (int i = 0; i < arrlongth; i++)
	{
		arrSum[i] = arr[i] + arr2[i];
	}
}
void PrintArray(int arr[100], int arrlongth)
{
	for (int i = 0; i < arrlongth; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int main()
{
	srand((unsigned)time(NULL));

	int arr[100], arr2[100], arrSum[100];
	int arrlongth = ReadPositiveNumber("How many elements ?\n");


	FillArrayWithRandomNumbers(arr, arrlongth);
	FillArrayWithRandomNumbers(arr2, arrlongth);

	SumOf2Arrays(arr, arrlongth, arr2, arrSum);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrlongth);

	cout << "\nArray 2 element:\n";
	PrintArray(arr2, arrlongth);

	cout << "\nSum of Array 1 and Array 2 element:\n";
	PrintArray(arrSum , arrlongth);
	return 0;
}
