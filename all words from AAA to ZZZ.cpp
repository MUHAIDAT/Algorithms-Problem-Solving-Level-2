#include <iostream>
#include <string>
using namespace std;



void  PrintAllFromAAAtoZZZ()
{
	string Word = "";
	int counter = 0;


	for (int a = 65; a <= 90; a++)
	{
		for (int b = 65; b <= 90; b++)
		{
			for (int c = 65; c <= 90; c++)
			{
				Word = Word + char(a);
				Word = Word + char(b);	
				Word = Word + char(c);		
						
				cout << Word << endl;								
																			
				Word = "";								
			}
		}
	}
	
}
int main()
{
    PrintAllFromAAAtoZZZ();
	return 0;
}

