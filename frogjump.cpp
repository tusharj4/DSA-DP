// Frog jump Problem
10 -> 20 -> 30 -> 10
+  -> +  -> +  -> +  = 40
+  -> +  -------> +  = 20
+  -------> +  -> +  = 30
#include <iostream>
using namespace std;
//Top - Down Approach 
int frogjump( int n, vector<int>& heights, vector<int>& dp )
{
    if( n == 0 )
    {
        return n;
    }
    if( dp[i] != -1 )
    {
        return dp[i];
    }
    int fs = frogjump( n-1, heights, dp ) + abs( heights[i] - heights[i-1] );
    if( n > 1 ){
        int ss = frogjump( n-2, heights, dp ) + abs( heights[i] - heigths[i-2] );
    }
    dp[i] = min(fs, ss);
    return dp[i];
}  
//Bottom - Up Approach 
int frogjump( int n, vector<int>& heights, vector<int>& dp )
{
    dp[0] = 0;
    if( dp[i] != -1 )
    {
        return dp[i];
    }
    for(int i = 1; i < n)
    int fs = dp[i-1] + abs( heights[i] - heights[i-1] );
    if( n > 1 ){
        int ss = dp[i-2] + abs( heights[i] - heigths[i-2] );
    }
    dp[i] = min(fs, ss);
    return dp[i];
}
//Space optimization 
int frogjump( int n, vector<int>& heights)
{
    int prev1 = 0;
    int prev2 = 0;
    if( n == 0 )
    {
        return 0;
    }
    int fs = prev1 + abs( heights[i] - heights[i-1] );
    if( n > 1 ){
        int ss = prev2 + abs( heights[i] - heigths[i-2] );
    }
    int curr = min(fs, ss);
    prev1 = prev2;
    prev2 = curr;
    return curr ;
}
int main()
{

}
 
