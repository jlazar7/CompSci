// Julia Lazar
// Extra Credit -add up to 20

using namespace std;
#include <iostream>
#include <vector>

// iterative boolean function that checks if two items in a vector add up to 20
bool AddUpTo20(const vector<int> & data)
{
   int n=data.size();
   for(int i=0; i<n-1;i++)  // iterate through the vector
   {
      int sum=0;
      for(int j=i+1;j<=n-1;j++)    // iterate through the list starting at i+1
      {
	 sum=data[i] + data[j];   // compare data [i] to each other item in the vector
	 if(sum == 20)     
	    return true;       //if two items in the vector add up to 20, return true
       }
   }

   return false;      // else, return false
}

// divide and conquer  boolean function that checks if two items in a vector add up to 20
bool DACAddUpTo20(vector <int>data, int first, int last)
{
   if(first == last)    // if there is one item in the list, return false
	return false;

   int mid = (first+last)/2;       // find mid point

   bool r1 = DACAddUpTo20(data, first, mid);     // split the list into two halves
   bool r2 = DACAddUpTo20(data, mid+1, last);

   if(r1||r2)
      return true;       // if either of the divided lists have two items that add up to 20, return true


   for(int i=first; i<=mid; i++)
   {
      for(int j=mid+1; j<=last; j++)
      {
	 if(data[i]+data[j] == 20)      // check for cross pairs between both divided lists
	     return true;               // if two items from the divided lists = 20, return true
      }
   }

   return false;     // else return false
}

// recursive boolean function that checks if two items in a vector add up to 20
bool RAddUpTo20(vector <int> data, int first, int last)
{
   // base case
   if(first == last)
	return false;
  
  // check if first two pairs = 20, if they do, return true 
  else if(data[first] + data[last] == 20)
	return true;
 
  // if they do not equal 20, call the function and decrease last by one each time, while first remains the same
  else if(data[first] + data[last] != 20)
       return RAddUpTo20(data,first,last-1);

  // after checking the value = first, increase first by one
  return RAddUpTo20(data,first+1, last);
} 


int main()
{

   vector <int> a = {16,4,3,6,7};
   vector <int> b = {2,3,4,5,6,7};
   bool iterative, recursive, dac;

   iterative = AddUpTo20(a);
   recursive = RAddUpTo20(b,0,b.size());
   dac = DACAddUpTo20(a,0,a.size());

   
    cout << "iteratively: " << endl;
    if(iterative == true)
       cout << "there are two items in the list that add up to 20" << endl;
    else
       cout << "no two items in the list add up to 20" << endl;
    cout << endl;

    cout << "recursively: " << endl;
    if(recursive == true)
       cout << "there are two items in the list that add up to 20" << endl;
    else
       cout << "no two items in the list add up to 20" << endl;
    cout << endl;

    cout << "DAC: " << endl;
    if(dac == true)
       cout << "there are two items in the list that add up to 20" << endl;
    else
       cout << "no two items in the list add up to 20" << endl;
    cout << endl;

 return 0;
}
   
   
