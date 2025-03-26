class Solution {
public:
    void printf(vector<vector<int>> &ans, vector<int>& nums, vector<int> &ds, int i){

        if(i == nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        printf(ans, nums, ds, i+1);
        ds.pop_back();
        printf(ans, nums, ds, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        printf(ans, nums, ds, 0);
        return ans;
    }
};