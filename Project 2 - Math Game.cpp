#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

enum enOperation { ADDITION = 1, SUBTRACTION = 2, MULTIPLICATION = 3, DIVISION = 4, Mix = 5 };
enum enDifficultylevel { EASY = 1, MEDIUM = 2, HARD = 3, MixLevel = 4 };

int RandNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

enDifficultylevel ReadDifficultyLevel()
{
    short Choicelevel;
    do
    {
        cout << "Enter Difficulty Level: [1] EASY, [2] MEDIUM, [3] HARD, [4] Mix ? ";
        cin >> Choicelevel;
    } while (Choicelevel < 1 || Choicelevel > 4);

    return (enDifficultylevel)Choicelevel;
}

enOperation ReadOperationChoice()
{
    short ChoiceType;
    do
    {
        cout << "Enter Operation: [1] ADD, [2] SUB, [3] MUL, [4] DIV, [5] Mix ? ";
        cin >> ChoiceType;
    } while (ChoiceType < 1 || ChoiceType > 5);

    return (enOperation)ChoiceType;
}

void GetRange(enDifficultylevel& Level, int& From, int& To)
{
    if (Level == enDifficultylevel::MixLevel)
        Level = (enDifficultylevel)RandNumber(1, 3);

    if (Level == enDifficultylevel::EASY) { From = 1; To = 10; }
    else if (Level == enDifficultylevel::MEDIUM) { From = 10; To = 100; }
    else { From = 100; To = 1000; }
}

float RightAnswer(int FirstNumber, int SecondNumber, enOperation OperationType)
{
    switch (OperationType)
    {
    case enOperation::ADDITION: return FirstNumber + SecondNumber;
    case enOperation::SUBTRACTION: return FirstNumber - SecondNumber;
    case enOperation::MULTIPLICATION: return FirstNumber * SecondNumber;
    case enOperation::DIVISION: return (float)FirstNumber / SecondNumber;
    default: return 0;
    }
}

bool AskOneQuestion(enOperation OpType, enDifficultylevel Level)
{
    int From, To, A, B;
    GetRange(Level, From, To);

    A = RandNumber(From, To);
    B = RandNumber(From, To);

    if (OpType == enOperation::Mix)
        OpType = (enOperation)RandNumber(1, 4);

    switch (OpType)
    {
    case enOperation::ADDITION: cout << A << " + " << B << " = ? "; break;
    case enOperation::SUBTRACTION: cout << A << " - " << B << " = ? "; break;
    case enOperation::MULTIPLICATION: cout << A << " * " << B << " = ? "; break;
    case enOperation::DIVISION: cout << A << " / " << B << " = ? "; break;
    }

    float UserAnswer;
    cin >> UserAnswer;

    float Correct = RightAnswer(A, B, OpType);

    if (UserAnswer == Correct)
    {
        cout << "✅ Correct!\n";
        return true;
    }
    else
    {
        cout << "❌ Wrong, correct answer = " << Correct << "\n";
        return false;
    }
}

void PlayGame()
{
    int Rounds;
    cout << "How many questions? ";
    cin >> Rounds;

    enDifficultylevel Level = ReadDifficultyLevel();
    enOperation OpType = ReadOperationChoice();

    int Right = 0, Wrong = 0;

    for (int i = 1; i <= Rounds; i++)
    {
        cout << "\n--- Question " << i << " ---\n";
        if (AskOneQuestion(OpType, Level))
            Right++;
        else
            Wrong++;
    }

    cout << "\n========= Game Summary =========\n";
    cout << "Total Questions: " << Rounds << "\n";
    cout << "Right Answers: " << Right << "\n";
    cout << "Wrong Answers: " << Wrong << "\n";
    cout << "================================\n";
}

int main()
{
    srand((unsigned)time(NULL));

    char Again;
    do
    {
		system("cls");
        PlayGame();
        cout << "Play Again? (Y/N): ";
        cin >> Again;
    } while (Again == 'Y' || Again == 'y');

    return 0;
}
