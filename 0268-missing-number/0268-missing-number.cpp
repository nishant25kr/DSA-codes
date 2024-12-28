class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int x;
        vector<int> hash(n + 1, 0);

        for (int i=0;i<n;i++){
            hash[nums[i]]=1;
        }
    
        for(int j=0;j<=n;j++){
            if(hash[j]==0){
                return j;
            }
        }
        return -1;
    }  
};