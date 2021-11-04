// Julia Lazar
// Dec. 4, 2020
// R02 - code for tik tac toe

#include <iostream>
using namespace std;

// prototypes
char printX(int);
char printO(int);
bool finalWinner(char&);

// global
char ttt[3][3];

int main()
{
   //variables
   char player;
   int counter, number, row, col, i;
   char  w;

   // init
   cout << endl;
   cout << "Welcome to the Tic Tac Toe game!" << endl;
   cout << endl;

   w = false;
   player = 'X';
   counter = 0;
   for(row = 0; row < 3; row++)
   {
      for(col = 0; col < 3; col ++)
      {
         ttt[row][col] = '1' + counter;
	 counter ++;
      }
   }
   
   // processing
   do
   {
      for(i = 0; i < 9; i++)
      {
  	 cout << endl;
	 cout << endl;
	 for(row = 0; row < 3; row++)
	 {
	    for(col =0; col < 3; col++)
	    {
		cout << ttt[row][col] << "  ";
	    }
	    cout << endl;
	  }

	cout << endl;
	cout << player << " what is your move? (1-9): ";
	cin  >> number;

	//  players
	if(player == 'X')
	{
	   player = 'O';
	   printX(number);
	}	
	else
	{
	   player = 'X';
	   printO(number);
	} 

	finalWinner(w);

	//output
	if(finalWinner(w) == true)
	{
	   cout << endl;
	   cout << "Player " << w << " won the game!" << endl;
  	   break;
	}
     }    
   }while(finalWinner(w) == false && i<9);

   // output
   if(finalWinner(w) == false)
   {
     cout << endl;
     cout << "There was no winner!" << endl;
     cout << endl;
   }
return 0;
}

// function definition
char printX(int move)
{
   int row=0 , col=0;
   	move--;
   	row = move / 3;
   	col = move % 3;
   	return ttt[row][col] = 'X';
   
}

char printO(int move)
{   
   int row=0, col=0;
   	move --;
   	row = move / 3;
   	col = move % 3;
   return  ttt[row][col] = 'O';
}


bool finalWinner(char& w)
{
   // X Horizontal
   if(ttt[0][0] == 'X' && ttt[0][1] == 'X' && ttt[0][2] == 'X')
   {
      w = 'X';
      return true;
   }
   else  if(ttt[1][0] == 'X' && ttt[1][1] == 'X' && ttt[1][2] == 'X')
   {
      w = 'X';
      return true;
   }
   else if(ttt[2][0] == 'X' && ttt[2][1] == 'X' && ttt[2][2] == 'X')
   {
      w = 'X';
      return true;
   }

   // X Vertical
   if(ttt[0][0] == 'X' && ttt[1][0] == 'X' && ttt[2][0] == 'X')
   {
     w = 'X';
     return true;
   }
   else if(ttt[0][1] == 'X' && ttt[1][1] == 'X' && ttt[2][1] == 'X')
   {
     w = 'X';
     return true;
   }
   else if(ttt[0][2] == 'X' && ttt[1][2] == 'X' && ttt[2][2] == 'X')
   {
     w = 'X';
     return true;
   }

   // X diagnol
   if(ttt[0][0] == 'X' && ttt[1][1] == 'X' && ttt[2][2] == 'X')
   {
     w = 'X';
     return true;
   }
   else if(ttt[0][2] == 'X' && ttt[1][1] == 'X' && ttt[2][0] == 'X')
   {
     w = 'X';
     return true;
   }

   // O Horizontal
   if(ttt[0][0] == 'O' && ttt[0][1] == 'O' && ttt[0][2] == 'O')
   {
      w = 'O';
      return true;
   }
   else  if(ttt[1][0] == 'O' && ttt[1][1] == 'O' && ttt[1][2] == 'O')
   {
      w = 'O';
      return true;
   }
   else if(ttt[2][0] == 'O' && ttt[2][1] == 'O' && ttt[2][2] == 'O')
   {
      w = 'O';
      return true;
   }

   // O Vertical
   if(ttt[0][0] == 'O' && ttt[1][0] == 'O' && ttt[2][0] == 'O')
   {
     w = 'O';
     return true;
   }
   else if(ttt[0][1] == 'O' && ttt[1][1] == 'O' && ttt[2][1] == 'O')
   {
     w = 'O';
     return true;
   }
   else if(ttt[0][2] == 'O' && ttt[1][2] == 'O' && ttt[2][2] == 'O')
   {
     w = 'O';
     return true;
   }

   // O diagnol
   if(ttt[0][0] == 'O' && ttt[1][1] == 'O' && ttt[2][2] == 'O')
   {
     w = 'O';
     return true;
   }
   else if(ttt[0][2] == 'O' && ttt[1][1] == 'O' && ttt[2][0] == 'O')
   {
     w = '0';
     return true;
   }
   else
     return false;
}

