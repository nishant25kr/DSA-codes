class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {

        int i=0;
        int j=0;
        while (j<nums.size() and i<nums.size()){
            if( nums[j]%2 == 0){
                swap(nums[i],nums[j]);
                i++;
                // j++;-
            }
            // else if(nums[i]==0 and nums[j]==0){
                j++;

            // }
            // else if(nums[j]==0 and nums[i]!=0){
            //     swap(nums[j],nums[i]);
            //     i++;
            //     j++;
            // }

        }
        return nums;
        
    }
};