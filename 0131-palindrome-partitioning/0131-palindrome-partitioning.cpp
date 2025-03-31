class Solution {
public:
    bool check_palen(string s, int start, int end) {
        while (start < end) { // Fixed: start < end (not start <= end)
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    void func(int index, string s, vector<vector<string>> &ans, vector<string> &path) {
        if (index == s.size()) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++) { // Fixed: i starts from index
            if (check_palen(s, index, i)) { // Fixed: Correct function call
                path.push_back(s.substr(index, i - index + 1)); // Fixed: Push substring
                func(i + 1, s, ans, path);
                path.pop_back(); // Backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans; // Fixed type
        vector<string> path; // Fixed type
        func(0, s, ans, path);
        return ans; // Return the result
    }
};
