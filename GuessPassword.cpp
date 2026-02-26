#include <iostream>   
#include <string>     
using namespace std; 
string ReadPassword()
{
    string Password;
    cout << "Please enter a 3-Letter Password (all capital)? " << endl;
    cin >> Password;
    return Password;
}
bool GuessPassword(string OriginalPassword)
{
    cout << "\n"; 
    string word = "";  
    int counter = 0;

        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {

                    word = word + char(i);
                    word = word + char(j);
                    word = word + char(k);

                    counter++;

                    cout << "Trial [" << counter << "] : " << word << endl;

                    if ( word == OriginalPassword)
                    {
                        cout << "password :" << word << endl;
                        cout << "count [ " << counter << " ]." << endl;
                        return true;
                    }
                    word = "";
                }
            }
            cout << "\n____________________________\n";
        }
        return false;
}

int main()
{
    GuessPassword(ReadPassword());

    return 0;
}