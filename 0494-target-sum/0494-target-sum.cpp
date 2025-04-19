class Solution {
public:
    int f(int i,vector<int > &nums,int T){
        if(i < 0) return T==0;
        
        int plus = f(i-1, nums, T+nums[i]);
        int minus = f(i-1, nums, T-nums[i]);


        return plus+minus;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return f(n-1,nums,target);
    }
};