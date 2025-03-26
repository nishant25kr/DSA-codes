class Solution {
public:
    // bool check(vector<vector<int>> &ans, vector<int> ds){

    // }

     void printf(vector<vector<int>> &ans, vector<int>& nums, vector<int> &ds, int i){

        if(i == nums.size()){
            if(find(ans.begin(), ans.end(), ds) == ans.end()){
                ans.push_back(ds);
            }
                return;
        }
        ds.push_back(nums[i]);
        printf(ans, nums, ds, i+1);
        ds.pop_back();
        printf(ans, nums, ds, i+1);
    }


    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        printf(ans, nums, ds, 0);
        return ans;
        
    }
};