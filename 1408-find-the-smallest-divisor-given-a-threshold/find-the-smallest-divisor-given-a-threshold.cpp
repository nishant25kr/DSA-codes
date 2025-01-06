class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        // Define the search space
        int left = 1, right = *max_element(nums.begin(), nums.end());
        int result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Calculate the sum of divisions
            int sum = 0;
            for (int num : nums) {
                sum += (num + mid - 1) / mid; // Equivalent to ceil(num / mid)
            }

            // Check if the current divisor meets the threshold
            if (sum <= threshold) {
                result = mid; // Update result
                right = mid - 1; // Try for a smaller divisor
            } else {
                left = mid + 1; // Increase the divisor
            }
        }

        return result;
    }
};
