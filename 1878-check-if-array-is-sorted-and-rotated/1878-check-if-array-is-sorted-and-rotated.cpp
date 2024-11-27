class Solution {
public:
    bool check(vector<int>& nums) {
        bool check=false;
        int count=0;
        int length=nums.size();
        for(int i=0;i<length-1;i++){
            if(nums[i]>nums[i+1]){
                count++;
            }
            
        }
        if(count==1 and nums[0]>=nums[length-1]){
            check=true;
        } 
        if(count ==0){
            check=true;
        }

        return check;  

       
    }  
};