class Solution {
public:
    void findCombinations(int i, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) { 
            ans.push_back(ds); 
            return;
        }
        if (i == candidates.size() || target < 0) return;

        // Include the current element (we don't move to the next index since repetition is allowed)
        ds.push_back(candidates[i]);
        findCombinations(i, candidates, target - candidates[i], ds, ans);
        ds.pop_back();

        // Exclude the current element and move to the next index
        findCombinations(i + 1, candidates, target, ds, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(0, candidates, target, ds, ans);
        return ans;
    }
};
