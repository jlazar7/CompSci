// Julia Lazar
// October 24th, 2021
// Balanced Parenthesis

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// pre: determines whether or not there is a pair of parenthesis
bool isPair(char begin, char end)
{
   if(begin == '(' && end == ')')
	return true;

   else if(begin == '[' && end == ']')
        return true;

   else if(begin == '{' && end == '}')
	return true;
   
   return false;
}

//Extra function:  prints out what the unbalanced parenthesis is missing for the item at the top of the stack
 void isError(std::stack <char> item)
 {

    switch (item.top()) {
    case '(':
         cout << "The cause of the imbalance on the top of the stack is a missing )" << endl;
    break;

    case '[':
         cout << "The cause of the imbalance on the top of the stack is a missing ]" << endl;
    break;

    case '{':
         cout << "The cause of the imbalance on the top of the stack is a missing }" << endl;
    break;
    }
  }

// determines whether of not the expression is balanced
bool isBalanced(string bal)
{
   std::stack <char> item;
   for(int i=0; i < bal.length(); i++)
   {
	if(bal[i] == '(' || bal[i] == '[' || bal[i] == '{')
	{
	   item.push(bal[i]);
        }
        else if(bal[i] == ')' || bal[i] == ']' || bal[i] == '}')
        {
	    if(item.empty() || !isPair(item.top(), bal[i]))
            {
		return false;
	    }
	    else
	       item.pop();	
       }
    }

  if(!item.empty())
     isError(item);
  else
    return true;
 
   return item.empty();
}



int main()
{
   string array;

   cout << "Enter any expression" << endl;
   cin  >> array;

   if(isBalanced(array) == true)
      cout << "the expression is balanced" << endl;
   else
      cout << "the expression is not balanced" << endl;
      


}
