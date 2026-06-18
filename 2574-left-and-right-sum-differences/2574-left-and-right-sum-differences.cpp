class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> answer;
        vector<int> leftsum(nums.size());
        vector<int> rightsum(nums.size());

        int left = 0;
        int right = 0;

        // left sums
        for(int i = 0; i < nums.size(); i++){
            leftsum[i] = left;
            left += nums[i];
        }

        // right sums
        for(int i = nums.size()-1; i >= 0; i--){
            rightsum[i] = right;
            right += nums[i];
        }

        // difference
        for(int i = 0; i < nums.size(); i++){
            answer.push_back(abs(leftsum[i] - rightsum[i]));
        }

        return answer;
    }
};