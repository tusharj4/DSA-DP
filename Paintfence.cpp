#include <iostream>
using namespace std; 
/*
Question : Paint fence 
What Question says : No two same colours can appear more than twice in the sequence created and return the total number of 
                        combinations possible 
Topic : Dynamic programming 
DP-3
*/
//using simple recursion 
int PaintfenceRec(int n, int k)
{
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return (k+k*(k-1));
    }
    int ans = (PaintfenceRec(n-2, k) + PaintfenceRec(n-1, k))*(k-1);
    return ans;
}
//memoization
int PaintfenceMemo(int n, int k, vector<int>& dp)
{
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return (k+k*(k-1));
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    return dp[n] = (PaintfenceMemo(n-2, k, dp) + PaintfenceMemo(n-1, k, dp))*(k-1);
}
//Bottom up approach
int PaintfenceBot(int n, int k)
{
    vector<int> dp(n+1, 0);
    dp[1] = k;
    dp[2] = k+k*(k-1);
    int i ;
    for( i = 3; i<=n; i++)
    {
        dp[i] = (dp[i-2] + dp[i-1])*(k-1);
    }
    return dp[n];
}
//Space optimization
int PaintfenceSpace(int n, int k)
{
    int i, curr, prev1, prev2;
    prev1 = k;
    prev2 = k+k*(k-1);
    for(i=3; i<=n; i++)
    {
        curr = (prev1+prev2)*(k-1);
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}