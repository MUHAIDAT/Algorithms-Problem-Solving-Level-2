#include <iostream>   
#include <string>     
#include <cstdlib>    
#include <ctime>
using namespace std;
enum enPrimNotPrime {Prime = 1 , NotPrime = 2};
enPrimNotPrime CheckPrime(int Number)
{
	int M = round(Number / 2);

	for (int counter = 2; counter <= M; counter++)
	{
		if (Number % counter == 0)
			return enPrimNotPrime::NotPrime;
	}
	return enPrimNotPrime::Prime;

}
int RandomNumber(int From, int To)
{

	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}
void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
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
void CopyOnlyPrimeInArray(int arrSource[100], int arrDestination[100], int arrLength, int &arr2Length)
{
	int counter = 0;
	for (int i = 0; i < arrLength; i++)
	{
		if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
		{
			arrDestination[counter] = arrSource[i];
		counter++;

		}
	}
	arr2Length = --counter;
}
int main()
{
	srand((unsigned)time(NULL));
	int arr[100] , arrLength;


	FillArrayWithRandomNumbers(arr, arrLength);

	int arr2[100];
	int arr2Length = 0;
	CopyOnlyPrimeInArray(arr, arr2, arrLength, arr2Length);

	cout << "\nElement Array 1:\n";
	PrintArray(arr, arrLength);

	cout << "\nPrime Numbers in Array2:\n";
    PrintArray( arr2, arr2Length);

	
	return 0;
}

