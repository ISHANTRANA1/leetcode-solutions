class Solution {
public:
    int maximumCount(vector<int>& nums) {

        int n = nums.size();

        int left = 0;
        int right = n-1;
        int firstPositive = n;

        while(left <= right){

            int mid = left + (right-left)/2;

            if(nums[mid] > 0){
                firstPositive = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        left = 0;
        right = n-1;
        int firstNonNegative = n;

        while(left <= right){

            int mid = left + (right-left)/2;

            if(nums[mid] >= 0){
                firstNonNegative = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }


        int positiveCount =n- firstPositive;

        int negativeCount = firstNonNegative;


        return max(positiveCount, negativeCount);
    }
};