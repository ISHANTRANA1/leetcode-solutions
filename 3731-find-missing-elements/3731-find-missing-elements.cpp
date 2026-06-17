class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> temp;
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for(int i = 0; i < n-1; i++) {

            if(nums[i+1] - nums[i] > 1) {

                for(int x = nums[i]+1; x < nums[i+1]; x++) {
                    temp.push_back(x);
                }

            }
        }

        return temp;
    }
};