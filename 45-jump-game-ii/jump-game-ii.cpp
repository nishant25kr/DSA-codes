class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1); // Memoization table
        return minJumps(nums, 0, dp); // Start from index 0
    }
    
    int minJumps(vector<int>& nums, int ind, vector<int>& dp) {
        int n = nums.size();
        if (ind >= n - 1) return 0; // Base case: reached or exceeded last index
        
        if (dp[ind] != -1) return dp[ind]; // Check memoized result
        
        int mini = INT_MAX;
        for (int i = 1; i <= nums[ind]; i++) {
            int jumps = minJumps(nums, ind + i, dp);
            if (jumps != INT_MAX) mini = min(mini, jumps + 1);
        }
        
        return dp[ind] = mini;
    }
};
