#include <iostream>   
#include <string>     
#include <cstdlib>    
#include <ctime>
using namespace std;
int RandomNumber(int From, int To)
{

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

void FillArrayWithRandomNumbers(int arr[100], int& arrLength)
{

	cout << "how many elements to fill ?" << endl;
	cin >> arrLength;
	cout << endl;
	for (int i = 0; i < arrLength; i++)
	{
		arr[i] = RandomNumber(0, 100);
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
int MinElement(int arr[100], int arrLength)
{
	int  Minelement = arr[0];
	for (int i = 0; i < arrLength; i++)
	{

		if (Minelement > arr[i])

		{
			Minelement = arr[i];
		}

	}
	return Minelement;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100];
	int arrLength;


	FillArrayWithRandomNumbers(arr, arrLength);
	cout << "\nElement Array: ";
	PrintArray(arr, arrLength);

	cout << "\nMax element: ";
	cout << MinElement(arr, arrLength) << endl;
	return 0;
}