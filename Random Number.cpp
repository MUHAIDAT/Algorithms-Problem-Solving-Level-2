#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From ;
	return RandNum;

}
int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(36, 42) << endl;
	cout << RandomNumber(36, 42) << endl;
	cout << RandomNumber(36, 42) << endl;
	return 0;
}