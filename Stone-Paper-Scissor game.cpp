#include<iostream>
#include<cmath>
#include<string>
#include <cstdlib> 

using namespace std;

enum enChoice { Stone = 1, Paper = 2, Scissor = 3 };
enum enResult { Win = 1, Lose = 2, Draw = 3 };

int ReadPositiveNumber(string Message) // قراءة رقم موجب يمثل عدد تكرار اللعبة
{
	int Number;
	do
	{
		cout << Message;
		cin >> Number;
	} while (Number <= 0);
	return Number;
}
void WelcomeMassage()
{
	cout << "Welcome to the Stone-Paper-Scissor Game!" << endl;
	cout << "----------------------------------------" << endl;
	cout << "\n";
	
}
int IsChoiceValid() // اختيار اللاعب والتاكد من صحة الاختيار
{
	

	int Choice;	
	cout << "Please choose one of the following options: " << endl;
	cout << "1. Stone" << endl;
	cout << "2. Paper" << endl;
	cout << "3. Scissor" << endl;
	cin >> Choice;

	do
	{
		if (Choice > 0 || Choice < 4)
			return Choice;
		else
			cout << "Invalid choice, please choose again: ";
			cin >> Choice;
			cout << "\n";

	} while (Choice >= 1 || Choice <= 3);

      return Choice;
}

int GetComputerChoice()
{
	int ComputerChoice = rand() % 3 + 1;
	return ComputerChoice;
}

int GetPlayerChoice()
{
	int PlayerChpice;
	PlayerChpice = IsChoiceValid();
	return PlayerChpice;
}

void PrintComputer(int ComputerChoice)
{
	switch (ComputerChoice)
	{
	case enChoice::Stone:
		cout << "Computer choice is: Stone" << endl;
		break;
	case enChoice::Paper:
		cout << "Computer choice is: Paper" << endl;
		break;
	case enChoice::Scissor:
		cout << "Computer choice is: Scissor" << endl;
		break;
	default:
		cout << "Invalid choice!" << endl;
		break;
	}
}
void PrintPlayerChoice(int PlayerChoice)
{
	switch (PlayerChoice)
	{
	case enChoice::Stone:
		cout << "Your choice is: Stone" << endl;
		break;
	case enChoice::Paper:
		cout << "Your choice is: Paper" << endl;
		break;
	case enChoice::Scissor:
		cout << "Your choice is: Scissor" << endl;
		break;
	default:
		cout << "Invalid choice!" << endl;
		break;
	}
}

int GetWinner( int ComputerChoice, int PlayerChoice )      //قواعد اللعبة
{
	
		switch (PlayerChoice)
		{
		case enChoice::Stone:
			if (ComputerChoice == enChoice::Stone)
				return enResult::Draw;
			else if (ComputerChoice == enChoice::Paper)
				return enResult::Lose;
			else if (ComputerChoice == enChoice::Scissor)
				return enResult::Win;
			break;

		case enChoice::Paper:
			if (ComputerChoice == enChoice::Paper)
				return enResult::Draw;
			else if (ComputerChoice == enChoice::Scissor)
				return enResult::Lose;
			else if (ComputerChoice == enChoice::Stone)
				return enResult::Win;
			break;

		case enChoice::Scissor:
			if (ComputerChoice == enChoice::Scissor)
				return enResult::Draw;
			else if (ComputerChoice == enChoice::Stone)
				return enResult::Lose;
			else if (ComputerChoice == enChoice::Paper)
				return enResult::Win;
			break;

		default:
			cout << "Invalid player choice!" << endl;
			return -1; // Return an invalid result to indicate an error.
		}
	
	/*switch (PlayerChoice)
	{
	case enChoice::Stone:
		if (ComputerChoice == enChoice::Stone)
			return enResult::Draw;
		else if (ComputerChoice == enChoice::Paper)
			return enResult::Lose;
		else if (ComputerChoice == enChoice::Scissor)
			return enResult::Win;
		break;

	case enChoice::Paper:
		if (ComputerChoice == enChoice::Paper)
			return enResult::Draw;
		else if (ComputerChoice == enChoice::Scissor)
			return enResult::Lose;
		else if (ComputerChoice == enChoice::Stone)
			return enResult::Win;
		break;

	case enChoice::Scissor:
		if (ComputerChoice == enChoice::Scissor)
			return enResult::Draw;
		else if (ComputerChoice == enChoice::Stone)
			return enResult::Lose;
		else if (ComputerChoice == enChoice::Paper)
			return enResult::Win;
		break;

	default:
		cout << "Invalid player choice!" << endl;
		return -1; // Return an invalid result to indicate an error.
	}*/
}
void PrintResult(int result)
{
	switch (result)
	{
	case enResult::Win:
		cout << " You win!" << endl;
		system("color 2");
		break;
	case enResult::Lose:
		cout << " You lose!" << endl;
		system("color 4");
		cout << "\a";
		break;
	case enResult::Draw:
		cout << " It's a draw!" << endl;
		system("color 6");
		break;
	default:
		cout << "Error determining the result!" << endl;
		break;
	}
}

void ClearScreen()
{
	system("cls");
}
int GameRepeted()
{
	char choice;
	cout << "Do you want to play again? (y/n): ";
	cin >> choice;
	if (choice == 'y' || choice == 'Y')
	{
		ClearScreen();

		return 1; // Play again  
	}
	else if (choice == 'n' || choice == 'N')
		return 0; // Exit the game  
	else
	{
		cout << "Invalid input. Please enter 'y' or 'n'." << endl;
		return GameRepeted(); // Recursively ask again  
	}
}
void loopGameRepeted()
{
	do
	{
		int Number;
		WelcomeMassage();

		Number = ReadPositiveNumber("How many times do you want to repeat the game? ");
		for (int i = 0; i < Number; i++)
		{
        int ComputerChoice = GetComputerChoice();
		int PlayerChoice = GetPlayerChoice();

		PrintPlayerChoice(PlayerChoice);
		PrintComputer(ComputerChoice);

		int result = GetWinner( ComputerChoice, PlayerChoice);

		PrintResult(result);
		}
		

	} while (GameRepeted());
}


int main()
{
	srand((unsigned)time(NULL)); // Seed the random number generator.
	loopGameRepeted();
	return 0;
}

