//Coin Change Problem: binary version, at most K coins, and
// unlimited version
//Compile using g++ -std=c++11
#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <assert.h>
using namespace std;

void PrintVector (const vector<int> & v){
    cout <<"[";
    for (auto e:v){
        cout<<e<<" ";
    }
    cout <<"]";

}

vector<vector<int>> subsets (const vector<int> & coins, int first, int last)
{
    vector<vector<int>> result;

    if (first==last){
        vector<int> empty;
        result.push_back (empty);

        vector<int> oneElement;
        oneElement.push_back (coins[first]);
        result.push_back (oneElement);
    
        return result;
    }

    //general case
    result = subsets (coins, first+1, last);

    int size = result.size();
    for (int i=0;i<size;i++){
        vector<int> set = result[i];

        set.push_back (coins[first]);
        result.push_back (set);
    }
    return result;
}

/* Check if we we use at most K coins to make the given value or not
@param: coins: the set of coins to choose from
@param: first last: specify the range of coins we can choose from
@param: value the sum we are trying to make
@param: K the limit of the number of coins to use
@return true if it's possible to choose at most K coisn from coins[first...last]
 to make value, return false other wise
*/
bool CoinChangeK (const vector<int> & coins, int first, int last, int value, int K)
{
   vector<vector<int>> allSubs = subsets (coins, first, last);

   int num = allSubs.size();
  
   for (int i=0; i<num; i++){
    if (allSubs[i].size() <= K) {
        int sum=0;
        cout <<"checking subset:";
        PrintVector(allSubs[i]);
        cout <<endl;
        
        for (int j=0;j<allSubs[i].size(); j++)
            sum += allSubs[i][j];

        if (sum==value)
            return true;
        }
   }

   return false;
}

/* Return the minimum number of coins required to make the given value, and set the
parameter bestSolution to store the coins
@param: coins: all coins we can choose from, each coin can be used more than once
@param value: the sum to make
@param bestSolution: stores the set of coins that is best solution (using min # of coins)
@return the minimum # of coins required
*/
int UnlimitedCoinChange (const vector<int> & coins, int value, vector<int>& bestSolution)
{
     if (value==0){
        bestSolution.clear();
        return 0;
    }

    if (value<0){
        bestSolution.clear();
        return INT_MAX;
    }

    //General case
    int curMin = INT_MAX; //we don't have a solution yet
    vector<int> curBest;
    int curSol;

    for (int i=0;i<coins.size(); i++){
        int curSol = UnlimitedCoinChange (coins, value-coins[i], curBest);

        if (curSol!=INT_MAX) {
            if (curSol + 1 < curMin) {
                curBest.push_back (coins[i]);

                //update our current best solution (the number of coins, coins used)
                curMin = curSol + 1;
                bestSolution = curBest;
            }
        }
            
    }
    
    //sanity check:
    if (curMin!=INT_MAX)
        assert (curMin ==bestSolution.size());

       return curMin;
}

//Todo by you:
////////////////  Part 1: Tabulation version

/*Return the minimum number of coins we need to use to make the given @value,
assuming there are unlimited supplies for each type of coins given by @coins.
*/
int UnlimitedCoinChange_Tabulation (const vector<int> & coins, int value)
{
        //1. Declare the table (see step 2 above)
    vector<int>table(value+1,INT_MAX);
    //2. Based upon the base cases from UnlimitedCoinChange, fill out the initial entries of the table
    table[0]=0;
   // table[1]=INT_MAX;
    
  
    

      // 3. Write a for loop to solve all problems, from smallest (1) to largest (value)
            for (int cur_v=2; cur_v<=value; cur_v++)
            {      // solve subproblem cur_v, and store the solution in the table
                table[cur_v]= value;
                int tempMin=INT_MAX;
                int prevMin=INT_MAX;
                for(int j=0;j<coins.size();j++)
                {
                    if(cur_v - coins[j] >= 0)
                    {
                        if(cur_v == coins[j])
                        {
                            table[cur_v]= 1;
                            tempMin=1;
                           }
                    
                       //table[cur_v] = min(table[cur_v],table[cur_v-coins[j]]+1);

                    else
                    {
                        if(table[cur_v - coins[j]] != INT_MAX)
                        {
                            tempMin = table[cur_v-coins[j]]+1;
                            if(tempMin < prevMin)
                            {
                                table[cur_v] = tempMin;
                                prevMin = tempMin;
                            }
                        }
                    }
          
                    }

                   //Note: use the optimal substructure found in step 1
                //table[value]=table[cur_v];
             }
    
            }
       //4. Return solution stored in table for @value
   // if(table[value]!=INT_MAX)
        return table[value];
    
    

}




///////////////// Part 2: Memoized version ///////

int UnlimitedCoinChange_Wrapper (const vector<int> & coins, int value)
{
       //1. Declare and initialize all entries to -1, meaning all problems are not yet solved
    vector<int>solution(value+1,-1);

       //2. Call memoized recursive solution, and return whatâ€™s returned by the function
    UnlimitedCoinChange(coins,value,solution);

    return solution[value];
             
}



int UnlimitedCoinChange_Memoized (const vector <int> & coins, int value, vector<int> & subProblemSolutions)
{
    if(value == 0)
        subProblemSolutions[0]=0;
    
    if(value == 1)
        subProblemSolutions[value]=INT_MAX;
    
    if(value < 0)
        subProblemSolutions[value]=INT_MAX;

    int min = INT_MAX;
    vector<int> best;
    int sol;
    
    for(int i=0;i<coins.size();i++)
    {
        if(coins[i] > value){
        sol = UnlimitedCoinChange_Memoized(coins,value-coins[i],best);
            if(sol<min){
                best.push_back(coins[i]);
                min=sol;
                subProblemSolutions = best;
            }
        }
    
    if(subProblemSolutions[value] != INT_MAX)
        return subProblemSolutions[value];
    
    return INT_MAX;
}


///////////////// Part 3: Memoized version: finding out the coins used.../////


int UnlimitedCoinChange_WrapperExtended (const vector<int> & coins, int value, vector<int> & coinsUsed)
{
       //1. Declare and initialize both tables: all entries to -1, meaning all problems are not yet solved
    coinsUsed.resize(coins.size(),-1);
    
       //2. Call memoized recursive solution, and return whatâ€™s returned by the function
    
    UnlimitedCoinChange_Memoized(coins,value,coinsUsed);
             
       //3. Use the firstCoinUsed table to output all coins used
       return 0;
}


int UnlimitedCoinChange_MemoizedExtended (const vector <int> & coins, int value, vector<int> & subProblemSolutions, vector<int> & firstCoinUsed)
{
    return 0;
}


int main()
{
   vector<int> coins{2,5,3,10};
   vector<int> used;

   vector<int> values{4, 6,15, 18, 30, 41}; //use this to test
   


   //Test CoinChangeK
  cout <<"Enter coinchangek or unlimited to test the corresponding function:";
  string command;

  cin >> command;

  if (command=="coinchangek"){
      //we cannot make 20 using 2 or fewer coins
      if (CoinChangeK (coins, 0, coins.size()-1, 20, 2)!=false ||
              CoinChangeK (coins, 0, coins.size()-1, 5, 1)!=true ||
              CoinChangeK (coins, 0, coins.size()-1, 9, 3)!=false)
        
      {
        cout <<"fail coinchangek tests\n";
               return 1; //faild coinchangeK test
      }
    else{
        cout <<"pass coinchangek tests\n";
        return 0; //pass coinchangeK test
    }
  } else if (command=="unlimited"){
       //Test UnlimitedCoinChange
    vector<int> bestSolution;

       if (UnlimitedCoinChange (coins, 1,bestSolution)!=INT_MAX) {
              cout <<"Failed UnlimitedCoinChange case 1\n";
        return 1; //failed unlimited test
    }
      
       if (UnlimitedCoinChange (coins, 15, bestSolution)!=2) {
        cout <<"Failed UnlimitedCoinChange case 2\n";
        return 1;
    }
    vector<int> expectedSol{5,10};
        sort (bestSolution.begin(), bestSolution.end());
    if (bestSolution!=expectedSol){
        cout <<"Failed UnlimitedCoinChange case 2\n";
        return 1;

    }


       if (UnlimitedCoinChange (coins, 30, bestSolution)!=3) {
        cout <<"Failed UnlimitedCoinChange case 3\n";
        return 1;
    }
    vector<int> expectedSol3{10,10,10};
        sort (bestSolution.begin(), bestSolution.end());
    if (bestSolution!=expectedSol3){
        cout <<"Failed UnlimitedCoinChange case 3\n";
        return 1;

    }

        cout <<"Pass unlimitedCoinChange cases\n";
        return 0;
  } else if (command=="unlimitedTab"){
       //Test UnlimitedCoinChange
    vector<int> bestSolution;

       if (UnlimitedCoinChange_Tabulation (coins, 1)!=INT_MAX) {
              cout <<"Failed UnlimitedCoinChange_Tabulation case 1\n";
        return 1; //failed unlimited test
    }

       if (UnlimitedCoinChange_Tabulation (coins, 15)!=2) {
        cout <<"Failed UnlimitedCoinChange_Tabulation case 2\n";
        return 1;
    }

      
       if (UnlimitedCoinChange_Tabulation (coins, 30)!=3) {
        cout <<"Failed UnlimitedCoinChange case 3\n";
        return 1;
    }

        cout <<"Pass unlimitedCoinChange cases\n";
        return 0;

  } else if (command=="unlimitedMem"){

       
    vector<int> bestSolution;
      cout << UnlimitedCoinChange_Wrapper (coins, 1) << endl;
       if (UnlimitedCoinChange_Wrapper (coins, 1)!=INT_MAX) {
              cout <<"Failed UnlimitedCoinChange_Wrapper case 1\n";
        return 1; //failed unlimited test
    }

       if (UnlimitedCoinChange_Wrapper (coins, 15)!=2) {
        cout <<"Failed UnlimitedCoinChange_Wrapper case 2\n";
        return 1;
    }


       if (UnlimitedCoinChange_Wrapper (coins, 30)!=3) {
        cout <<"Failed UnlimitedCoinChange_Wrapper case 3\n";
        return 1;
    }

        cout <<"Pass unlimitedCoinChange_Wrapper cases\n";
        return 0;
  } else if (command=="unlimitedExt"){

       //Test UnlimitedCoinChange_WrapperExtended
    vector<int> bestSolution;

       if (UnlimitedCoinChange_WrapperExtended (coins, 1,bestSolution)!=INT_MAX) {
              cout <<"Failed UnlimitedCoinChangeWrapperExtended case 1\n";
        return 1; //failed unlimited test
    }

       if (UnlimitedCoinChange_WrapperExtended (coins, 15, bestSolution)!=2) {
        cout <<"Failed UnlimitedCoinChange_WrapperExetnded case 2\n";
        return 1;
    }
    vector<int> expectedSol{5,10};
        sort (bestSolution.begin(), bestSolution.end());
    if (bestSolution!=expectedSol){
        cout <<"Failed UnlimitedCoinChange case 2\n";
        return 1;

    }


       if (UnlimitedCoinChange_WrapperExtended (coins, 30, bestSolution)!=3) {
        cout <<"Failed UnlimitedCoinChange case 3\n";
        return 1;
    }
    vector<int> expectedSol3{10,10,10};
        sort (bestSolution.begin(), bestSolution.end());
    if (bestSolution!=expectedSol3){
        cout <<"Failed UnlimitedCoinChange case 3\n";
        return 1;

    }

        cout <<"Pass unlimitedCoinChange_WrapperExtended cases\n";
        return 0;
  }

}


