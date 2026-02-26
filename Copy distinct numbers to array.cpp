#include<iostream>
using namespace std;

int ReadPositiveInArray(int &arrLength)

{
	do
	{
		cout << "Enter the number of the array: ";
		cin >> arrLength;

	} while (arrLength <= 0);
	cout << "\n";
	return arrLength;
}
void EnteringatrixValues(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << "Array[" << i << "] " ;
		cin >> arr[i];

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
short FindNumberPositiveInArray(int Number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;
	}
	return -1;
}
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
	return FindNumberPositiveInArray(Number, arr, arrLength) != -1;
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
	arrLength++;             
	arr[arrLength - 1] = Number;  
}
void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int SourceLength, int& DestinationLength)
{
	for (int i = 0; i < SourceLength; i++)
	{
		if (!IsNumberInArray(arrSource[i], arrDestination, DestinationLength))
		{
			AddArrayElement(arrSource[i], arrDestination, DestinationLength);
		}
	}
}
int main()
{
	int arrSource[100], arrDestination[100], SourceLength = 0, DestinationLength = 0;
	SourceLength = ReadPositiveInArray(SourceLength);
	EnteringatrixValues(arrSource, SourceLength);

	PrintArray(arrSource, SourceLength);

	CopyDistinctNumbersToArray(arrSource, arrDestination, SourceLength, DestinationLength);

	PrintArray(arrDestination, DestinationLength);

	return 0;
}


/*#include<iostream>
using namespace std;
void FillArray(int arr[100], int &arrLength)
{
	arrLength = 10;

	arr[0] = 10;
	arr[1] = 10;
	arr[2] = 10;
	arr[3] = 50;
	arr[4] = 50;
	arr[5] = 50;
	arr[6] = 70;
	arr[7] = 70;
	arr[8] = 70;
	arr[9] = 90;
}
void PrintArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		cout << arr[i] << " ";
	}
}
short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (arr[i] == Number)
			return i;  
	}
	return -1;
}
bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
	return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}
void AddArrayElement(int Number, int arr[100], int &arrLength)
{
	arrLength++;
	arr[arrLength - 1] = Number;
}
void CopyDistinctNumbersToArray(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		if (!IsNumberInArray(arrSource[i], arrDestination, arrLength))
		{
			AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
		}
	}
}
int main()
{
	int arrSource[100], arrLength = 0, arrDestination[100], arrDestinationLength = 0;
	FillArray(arrSource, arrLength);

	cout << "Array element: \n";
	PrintArray(arrSource, arrLength);

	CopyDistinctNumbersToArray(arrSource, arrDestination, arrLength, arrDestinationLength);

	cout << "\n\nArray 2 :\n";
	cout << "\n\nArray 2 :\n";
	PrintArray(arrDestination, arrDestinationLength);
	return 0;
}*/