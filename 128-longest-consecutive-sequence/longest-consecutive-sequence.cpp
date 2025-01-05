class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0; // Handle empty array edge case

        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int x : numSet) { // Use the set directly for iteration
            // Check if x is the start of a sequence
            if (numSet.find(x - 1) == numSet.end()) {
                int count = 1;
                while (numSet.find(x + 1) != numSet.end()) {
                    x += 1;
                    count++;
                }
                longest = max(longest, count);
            }
        }

        return longest;
    }
};