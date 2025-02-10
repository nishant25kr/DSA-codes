class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count;
        int n=nums.size();
        for(int i=0;i<nums.size();i++ ){
            count=0;
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    count++;
                }
            }
            // if(n%2!=0){
            //     if(count>(n+1/2)) return nums[i];
            // }
            if(count>n/2) return nums[i];
           
        }
        return 0;
          
    }
};