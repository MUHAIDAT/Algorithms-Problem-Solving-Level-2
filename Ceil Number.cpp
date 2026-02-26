#include <iostream>  
using namespace std;

float ReadNumber()
{
    float Number;
    cout << "Please enter a float number? ";
    cin >> Number;
    return Number;
}



float MyCeil(float Number)
{
    if (Number > 0)
    {
        return int(Number) + 1;

    }
    else
    {
        return int(Number) ;
    }
}

int main()
{
    float Number = ReadNumber();
    cout << "Custom my floor of " << Number << " is " << MyCeil(Number) << endl;

    cout << "C++ Round Result: " << ceil(Number) << endl;

    return 0;
}