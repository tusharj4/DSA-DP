/*
Dynamic programming
-------------------

1. Past se Sikho
2. Jo ek baar calculate kar chuke ho, usse
    dubara calculate karne ki jarurat ni hai 

3 ways to solve a DP problem:
1 -> Top - Down -> Use recursion alongwith memoization
2 -> Bottom - Up -> also known as Tablulation method
3 -> Space optimization -> O(1)

When to apply DP?
conditions: 1) Over-lapping sub problems, 
            2) Optimal substructure - Optimal soln of bigger problem can be calculated 
                                      using optimal soln of smaller problem

For Fibonacci Series : ->
*/
#include <iostream>
using namespace std;
// Top down appproach / Recursion + memoization -> TC O(n) | SC O(n)[recusrive stack space complexity] + O(n)[Dp array]
int Fibonacci(int n)
{
    // 1. Create DP array
    vector<int> dp(n+1, -1);
    // Base case
    if( n == 1 || n == 0 )
    {
        return n;
    }
    // 3. Base case ke just baad 
    //    check of answer already exists, if yes then return the ans.
    if( dp[n] != -1 )
    {
        return dp[n];
    }
    // 2. store the answer in dp
    dp[n] = Fibonacci(n-1) + Fibonacci(n-2);

    return dp[n];
}

// Bottom Up approach - O(n) TC | O(n) SC
int BottomupSolve( int n)
{
    // 1. Create dp array
    vector<int> dp(n+1, -1);
    // 2. Observe Base case in our solution 
    dp[0] = 0;
    if( n == 0 )
    {
        return dp[0];
    }
    dp[1] = 1;
    if( n == 1 )
    {
        return dp[1];
    }
    for( int i = 2; i<=n; i++ )
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

//Sapce Optimization -> TC O(n) | SC O(1)
int SpaceoptSolve( int n )
{
    // Observe the base case and accordingly define the variables
    int prev1 = 0;
    int prev2 = 1;
    if( n == 0 )
        return prev1;
    if( n == 1 )
        return prev2;
    int curr;
    for( int i = 2; i<=n; i++ )
    {
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    return curr;
}

int main()
{
    int n;
    cout << "Enter the number of terms you want : " <<  endl;
    cin >> n;
    cout << "The nth term of the Fibonacci series is(Bottom Up) : " << BottomupSolve(n);
    cout << "The nth term of the Fibonacci series is(Space opt) : " << SpaceoptSolve(n);
    return 0;
}