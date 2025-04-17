class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // Create a DP array and initialize all values to a large number (amount + 1)
        vector<int> dp(amount + 1, amount + 1);
        
        // Base case: 0 coins needed to make amount 0
        dp[0] = 0;

        // Loop through all amounts from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // Try every coin
            for (int coin : coins) {
                if (i - coin >= 0) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // If we couldn't find a way to form the amount, return -1
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
