class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int left = 0;
        int zeroCount = 0;
        int maxLen = 0;

        for (int right = 0; right < nums.size(); right++) {

            // If current element is 0,
            // we would need to flip it.
            if (nums[right] == 0)
                zeroCount++;

            // If flips required exceed k,
            // shrink the window.
            while (zeroCount > k) {

                if (nums[left] == 0)
                    zeroCount--;

                left++;
            }

            // Current window is valid.
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};