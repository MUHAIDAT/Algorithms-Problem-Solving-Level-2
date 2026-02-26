#include <iostream>   
#include <string>     
#include <cstdlib>    
#include <ctime>
using namespace std;

enum  enCharType {
	SamallLetter = 1,       // Represents lowercase letters (ASCII 97 to 122).
	CapitalLetter = 2,      // Represents uppercase letters (ASCII 65 to 90).
	SpecialCharacter = 3,   // Represents special characters (ASCII 33 to 47).
	Digit = 4               // Represents digits (ASCII 48 to 57).
};
int RandNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}
char GetRandomCharacter(enCharType CharType)
{
	switch (CharType)
	{
	case enCharType::SamallLetter:
	{
		return char(RandNumber(97, 122));
		break;
	}
	case enCharType::CapitalLetter:
	{
		return char(RandNumber(65, 90));

		break;
	}
	case enCharType::SpecialCharacter:
	{
		return char(RandNumber(33, 47));

		break;
	}
	case enCharType::Digit:
	{
		return char(RandNumber(48, 57));

		break;
	}
	}
	return '\0';
}
int ReadPositiveNumber(string message)
{
	int Number = 0;
	do
	{
		cout << message << endl;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
string GenerateWord(enCharType CharType, short Length)
{
	string Word;
	for (int i = 1; i <= Length; i++)
	{
		Word = Word + GetRandomCharacter(CharType);
	}
	return Word;
}
string GenerateKey()
{
	string Key = "";

	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
	return Key;
}

void GenerateKeys(short NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Key [" << i << "] : ";
		cout << GenerateKey() << endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	GenerateKeys(ReadPositiveNumber("please enter a positive number?\n"));
	return 0;

}