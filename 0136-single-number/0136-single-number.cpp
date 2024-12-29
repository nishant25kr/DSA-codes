class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count;
        int n=0;
        for( int i=0 ; i<nums.size() ; i++){
            count=0;
            n=nums[i];
            for(int j=0;j<nums.size();j++){
                if(nums[j] == n){
                    count++;
                }

            }
            if(count == 1){
                return n;
            }
        }
        return -1;
    }
};