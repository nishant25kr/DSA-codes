class Solution {
public:
    int f(int i, vector<int>& coins, int T, vector<vector<int>> &dp){
        if(i == 0){
            return (T % coins[0] == 0); //? 1 : 0;
        }

        if(dp[i][T] != -1) return dp[i][T];

        int notTake = f(i-1, coins, T, dp);
        int take = 0;
        if(T >= coins[i]) take = f(i, coins, T - coins[i], dp);

        return dp[i][T] = notTake + take;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (amount == 0) return 1; // Important base case
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return f(n - 1, coins, amount, dp);
    }
};
