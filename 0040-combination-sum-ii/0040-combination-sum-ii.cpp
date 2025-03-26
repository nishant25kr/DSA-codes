class Solution {
public:
     void findCombinations(int i, vector<int>& candidates, int target, vector<int>& ds, vector<vector<int>>& ans) {
        if (target == 0) { 
            ans.push_back(ds); 
            return;
        }

        for (int j = i; j < candidates.size(); j++) {
            if (j > i && candidates[j] == candidates[j - 1]) continue; // Skip duplicates
            if (candidates[j] > target) break; // Stop if the number is greater than target

            ds.push_back(candidates[j]);
            findCombinations(j + 1, candidates, target - candidates[j], ds, ans); // Move to next index
            ds.pop_back();
        }
    }

//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         vector<vector<int>> ans;
//         vector<int> ds;
//         sort(candidates.begin(), candidates.end()); // Sorting helps in skipping duplicates
//         findCombinations(0, candidates, target, ds, ans);
//         return ans;
//     }
// };
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(),candidates.end());
        findCombinations(0, candidates, target, ds, ans);
        return ans;
        
    }
};