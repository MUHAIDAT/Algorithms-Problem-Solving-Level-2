#include<iostream>
using namespace std;

int RandomNumber(int To, int From)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FullArrayWithRandomNumber(int arr[100], int &arrLength)
{
	cout << "Enter number of elements\n";
		cin >> arrLength;

	for (int i = 0; i < arrLength; i++)
	{
		
		 arr[i] = RandomNumber(1, 10);
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

void CopyArrayInReverseOrder(int arrSourse[100], int arrDestination[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		arrDestination[i] = arrSourse[arrLength - 1 - i];
	}
}
int main()
{
	srand((unsigned)time(NULL));

	int arr[100];
	int arrLength;
	FullArrayWithRandomNumber(arr, arrLength);

	int arrDestination[100];
	CopyArrayInReverseOrder(arr, arrDestination, arrLength);

	cout << "\nArray 1 elements:\n";
	PrintArray(arr, arrLength);

	cout << "\nArray 2 elements:\n";
	PrintArray(arrDestination, arrLength);
	return 0;



}