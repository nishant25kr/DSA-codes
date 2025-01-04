class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            count=0;
            for(int j=i;j<nums.size();j++){
                count=count+nums[j];
                if(count==k){
                ans++;
                }
            }

        }
        return ans;    
    }
};