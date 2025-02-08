class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0, zeroCount = 0, maxlen = 0;

        while (right < nums.size()) {
            if (nums[right] == 0) {
                zeroCount++;
            }

            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;  // Shrink window from left
            }

            maxlen = max(maxlen, right - left + 1);
            right++;  // Expand window from right
        }

        return maxlen;
    }
};
