#include<iostream>  
using namespace std;  

int ReadPositiveNumber(string Message)  
{  
int Number;  
do  
{  
	cout << Message;  
	cin >> Number;  
} while (Number <= 0);  
return Number;  
}  

void FillArray(int arr[100], int& arrLength)  
{  
for (int i = 0; i < arrLength; i++)  
{  
	cout << "[" << i + 1 << "] :";  
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

int CountOddNumber(int arr[100], int arrLength)  
{  
int OddCount = 0;  
for (int i = 0; i < arrLength; i++)  
{  
	if (arr[i] % 2 != 0)  
		OddCount++;  
}  
return OddCount;  
}  

int main()  
{  
int arr[100], arrLength;  
arrLength = ReadPositiveNumber("Enter the number of elements in the array: ");  

FillArray(arr, arrLength);  
PrintArray(arr, arrLength);  
cout << "The count of odd numbers in the array = " << CountOddNumber(arr, arrLength) << endl;  
return 0;  
}