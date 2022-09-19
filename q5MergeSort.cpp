/* Illustration of MergeSort implementation on vector
   Compile using g++ --std=c++11 q5mergesort.cpp
                     ^ some features used is implemented in v11 of C++
   Author: X. Zhang for CISC4080
   Known bugs: none
   Last modification date: 3/11/2022
*/

#include <iostream>
#include <vector>
using namespace std;

// Todo1: Add cout statement to MergeSort () to print out
//   a line for each time this function is called, show the parameter
//   a line for each time we return from this function, show the parameter
//    format: MergeSort called,   parameter=[2,8,1,7]
//            MergeSort returned, parameter=[8,7,2,1]

//Todo2: Implement Q5 (a) following the following steps
// 1) Modify ALL comments as needed,
// 2) Modify BinaryMergeSortedList() based upon the updated comments
//    i.e., to merge l1, l2, both already in descending order, into list
//    so that list will be in descending order


/* Merge two sorted vectors' elements into one sorted vector
@param l1, l2: two sorted vectors
@param list: the vector to hold the merging result
@pre-condcition: elements in l1, l2 are in ascending order
@post-condcition: list contains elements from l1 and l2, in descending order */
void BinaryMergeSortedList (const vector<int> l1, const vector<int> l2, vector<int> & list)
{
    //Idea: as well as l1 and l2 both have elements left to be copied to list,
    // compare the "front runner", and copy the larger one to next slot in list.
    // When only one of l1, l2 have elements left, copy all remaining elements to list
    //  one by one.

    //make sure list has exact same # of elements as l1, l2 combined:
    // (by dropping extra or adding 0 to the end)
    // subsequently, we can use list[k] or list.at(k) to refer to each element...
    // more efficient than:
    //      1) first: list.clear(); //make list an empty list
    //      2) and then: list.push_back(l1[i++]); //to add a new element into
    //         the back (end of list).

    list.resize(l1.size()+l2.size());

    int i,j,k; //used to index l1, l2 and list respectively
    i=j=k=0; //start from first position

    while (i<l1.size() && j < l2.size()){
        if (l1[i] >= l2[j]) //comparison operation
            //copy larger one to list, and advance indices
            list[k++] = l1[i++]; //copy operation
        else
            list[k++] = l2[j++];    //copy operation
    }

    //copy remaining elements to list
    while (i<l1.size()) //if l1 is not done yet
        list[k++] = l1[i++]; //copy operation

    while (j<l2.size()) //if l2 is not done yet
        list[k++] = l2[j++]; //copy operation

}

void sort(vector<int> list)
{
   for(int i = 0; i < list.size(); i++){
    for(int j = i+1; j < list.size(); j++){
      if(list[i] < list[j])   // if list[i] value is greater than list[j] value swap them
      {
          int temp = list[i]; //swap
          list[i] = list[j];
          list[j] = temp;
      }
    }
   }
}
/* sort the vector into ascending order
@param list: the vector of int to be sorted
@pre-condiction: list has been initialized with some data
@post-condition: the integers stored in list are rearranged into
 ascending order */
void MergeSort (vector<int> & list)
{
    cout << "MergeSort called, parameters= [";
    for(int i=0; i <list.size(); i++)
    {
        cout << list[i] << ",";
    }
    cout << "]";
    cout << endl;
    
    //base case 1
    if (list.size()==1)
        return;

    //Todo3: Add a base case for the case when list contains two elements
        //  only
    if(list.size() == 2)
    {
        if(list[0]<list[1])
        {
            int temp = list[0];
            list[0] = list[1];
            list[1] = temp;
        }
        else
            return;
    }


    //Todo4: Add a third base case: when list's length is less than
    // 50, call insertion sort (from your lab2), or bubblesort (from your
    // lab1) to sort it
    if(list.size()<50)
    {
        sort(list);
    }

    //general case: divide and conquer
    
    //divide part
    int n=list.size();
    int mid = (0+n-1)/2; //averge of first and last index

    vector<int> leftHalf(list.begin(),list.begin()+mid+1);
        // range constructor: initilize with elements from a range of existing vector:
        //   from first iterator (including) to last iterator (not included)
        //https://www.cplusplus.com/reference/vector/vector/vector/
    vector<int> rightHalf(list.begin()+mid+1,list.end());

    //conquer part: solve the two subproblems recursively (and independently from
    // each other
    MergeSort (leftHalf);
    MergeSort (rightHalf);


    //Combine part: merge data from the two sorted halves
    // back into list, in descending order
    BinaryMergeSortedList (leftHalf, rightHalf, list);
  
        cout << "MergeSort returned, parameters= [";
        for(int i=0; i <list.size(); i++)
        {
            cout << list[i] << ",";
        }
        cout << "]";
        cout << endl; 
}


int main()
{
    vector<int> a{6,4,3,8,2,5,1,7};

    MergeSort (a);
    
    cout<<"result:";
    //use iterator to go through vector a
    //for (vector<int>::iterator it=a.begin(); it<a.end(); it++)
        //cout <<*it <<" ";
    for (auto element:a) //supported in C++11, element's type is auto
        cout <<element<<" ";
    cout <<endl;

    cout << endl;
    //Todo 5:
    // Generate random vector of size of length n=500
    // and call your mergesort function on the vector
    vector<int> random;
    
   for (int i = 0; i <=500; i++)
   { 
      int b = rand() % 500+1;  
      random.push_back (b);
   }
             
    MergeSort(random);
    
    for (auto element:random) //supported in C++11, element's type is auto
        cout <<element<<" ";
    cout <<endl;

}
