class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans =nums[0];
        for(int i=1; i<nums.size(); i++){
            int oldMax =maxi;
            int oldMin =mini;
            maxi =max({nums[i], nums[i]*oldMax, nums[i]*oldMin});
            mini = min({nums[i], nums[i]* oldMax,nums[i]*oldMin});
            ans =max(ans, maxi);
        }
        return ans;
    }
};