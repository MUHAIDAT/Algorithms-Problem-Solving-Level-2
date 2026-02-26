#include <iostream>  
using namespace std;  

float ReadNumber() // Removed the parameter to avoid confusion and uninitialized use  
{  
   float Number; // Declare the variable inside the function  
   cout << "Please enter a float number? ";  
   cin >> Number;  
   return Number;  
}  

float GetFractionPart(float Number)  
{  
   return Number - int(Number);  
}  

float MyRand(float Number)  
{  
   int IntPart = int(Number);  
   float FractionPart = GetFractionPart(Number);  

   if (abs(FractionPart) >= 0.5)  
   {  
       if (Number > 0)  
           return ++IntPart;  
       else  
           return --IntPart;  
   }  
   else  
       return IntPart;  
}  

int main()  
{  
   float Number = ReadNumber(); // Correctly initialize 'Number' by calling ReadNumber  

   cout << "Custom my round of " << Number << " is " << MyRand(Number) << endl;  

   cout << "C++ Round Result: " << round(Number) << endl;  

   return 0;  
}