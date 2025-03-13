//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
    const int MOD = 1000000007;
  public:
    long long int top_down_helper(int n , vector<long long int> &dp)
    {
        if(n <= 1)
            return n;
            
        if(dp[n] != -1)
            return dp[n];
            
        return dp[n] = (top_down_helper(n-1,dp) + top_down_helper(n-2,dp))%MOD;
    }
    
    long long int topDown(int n) 
    {
        vector<long long int>dp(n+1,-1);
        return top_down_helper(n,dp);
    }
    long long int bottomUp(int n) 
    {
        vector<long long int>dp(n+1,-1);
        dp[0] = 0; dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2])%MOD;
        }
        
        return dp[n];
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends