// Julia Lazar
// Nov. 20, 2020
// R02- Coin Homework

#include <iostream>
using namespace std;

// prototypes
void computeCoins(int, int&, int&);

int main()
{
   // variables
   int amount, num;
   int quarter, dime, penny;
   char answer;

   do
   {
   // input
   cout << "Enter any amount of change from 1-99 cents: ";
   cin  >> amount;

   // output / processing
   cout << endl;
   cout << amount << " cents can be given as" << endl;
   computeCoins(25, num, amount);
   cout  << num <<  " quarter(s)" << endl;
   computeCoins(10, num, amount);
   cout << num << " dime(s)" << endl;
   computeCoins(1, num, amount);
   cout << num << " penny(pennies) " << endl;
   cout << endl;
   cout << "would you like to enter another amount? (y = yes, n = no): ";
   cin  >> answer;
   
   }while(answer == 'Y' || answer == 'y');
  
    cout << "Have a nice day!" << endl;

    return 0;
}

// function definition
void computeCoins(int coinValue, int& num, int& amountLeft)
{
   num = amountLeft / coinValue;
   amountLeft = amountLeft - (num * coinValue);
}
