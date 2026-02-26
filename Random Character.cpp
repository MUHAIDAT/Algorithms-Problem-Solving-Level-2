#include < iostream >
#include < string >
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
int main()
{
	srand((unsigned)time(NULL));

	cout << GetRandomCharacter(enCharType::SamallLetter) << endl;
	cout << GetRandomCharacter(enCharType::CapitalLetter) << endl;
	cout << GetRandomCharacter(enCharType::SpecialCharacter) << endl;
	cout << GetRandomCharacter(enCharType::Digit) << endl;

	return 0;

}