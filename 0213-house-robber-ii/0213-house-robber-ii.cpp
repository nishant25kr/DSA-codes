class Solution {
public:

    int f(vector<int> &num,int i,vector<int>&dp){
        if(i==0) return num[i];
        if(i<0) return 0;

        if(dp[i]!=-1) return dp[i];

        int pick = num[i] + f(num,i-2,dp);
        int npick = 0 + f(num,i-1,dp);

        return dp[i]= max(pick,npick);
         
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> temp1,temp2;
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        if(n==1) return nums[0];
        for(int i=0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(f(temp1,temp1.size()-1,dp1),f(temp2,temp2.size()-1,dp2));
        
    }
};