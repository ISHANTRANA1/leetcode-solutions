class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }

private:
    int mergeSort(vector<int>& nums, int low, int high) {
        // base case: 0 or 1 element has no pairs
        if (low >= high) {
            return 0;
        }

        int mid = low + (high - low) / 2;

        // pairs fully inside the left half + fully inside the right half
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);

        // count cross pairs (i in left half, j in right half)
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += j - (mid + 1);
        }

        // merge the two sorted halves
        merge(nums, low, mid, high);

        return count;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                temp.push_back(nums[left++]);
            } else {
                temp.push_back(nums[right++]);
            }
        }

        while (left <= mid) {
            temp.push_back(nums[left++]);
        }

        while (right <= high) {
            temp.push_back(nums[right++]);
        }

        // copy back into the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
    }
};