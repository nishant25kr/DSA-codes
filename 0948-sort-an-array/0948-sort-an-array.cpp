class Solution {
public:
    void merge(vector<int> &nums, int l, int mid, int h) {
        vector<int> left(nums.begin() + l, nums.begin() + mid + 1);
        vector<int> right(nums.begin() + mid + 1, nums.begin() + h + 1);
        
        int i = 0, j = 0, k = l;
        
        while (i < left.size() && j < right.size()) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            } else {
                nums[k++] = right[j++];
            }
        }
        
        while (i < left.size()) {
            nums[k++] = left[i++];
        }
        
        while (j < right.size()) {
            nums[k++] = right[j++];
        }
    }

    void mergesort(vector<int> &nums, int l, int h) {
        if (l >= h) return;

        int mid = l + (h - l) / 2;

        mergesort(nums, l, mid);
        mergesort(nums, mid + 1, h);
        merge(nums, l, mid, h);
    }

    vector<int> sortArray(vector<int>& nums) {
        int l = 0;
        int h = nums.size() - 1;
        mergesort(nums, l, h);
        return nums;
    }
};
