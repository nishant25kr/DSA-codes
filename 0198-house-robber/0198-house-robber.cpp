class Solution {
public:
    int f(vector<int>&nums, int i, vector<int>&dp){
        if(i==0) return nums[i];
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];

        int pick = nums[i] + f(nums,i-2,dp);
        int Npick = 0 + f(nums,i-1,dp);

        return dp[i] = max(pick,Npick);



    }

    int rob(vector<int>& nums) {
        int i=nums.size();
        int sum;
        vector<int >dp(i, -1);
        return f(nums,i-1,dp);

        
    }
};