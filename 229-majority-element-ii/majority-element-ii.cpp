class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;

        for (int i = 0; i < n; i++) {
            int count = 0;

            // Count occurrences of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[i] == nums[j]) {
                    count++;
                }
            }

            // If it appears more than n/3 times, add to result
            if (count > n / 3) {
                // Ensure no duplicates are added
                if (find(result.begin(), result.end(), nums[i]) == result.end()) {
                    result.push_back(nums[i]);
                }
            }
        }

        return result;
    }
};
