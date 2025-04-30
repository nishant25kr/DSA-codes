class Solution {
public:
    int f(int i, int trans, int k, vector<int>& prices, int n, vector<vector<int>>& dp){
        if(i == n || trans == 2*k) return 0;
        if(dp[i][trans] != -1) return dp[i][trans];

        if(trans % 2 == 0){
            return dp[i][trans] = max(-prices[i] + f(i+1, trans+1, k, prices, n, dp),
                                      f(i+1, trans, k, prices, n, dp));
        }
        return dp[i][trans] = max(prices[i] + f(i+1, trans+1, k, prices, n, dp),
                                  f(i+1, trans, k, prices, n, dp));
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return f(0, 0, k, prices, n, dp);
    }
};
