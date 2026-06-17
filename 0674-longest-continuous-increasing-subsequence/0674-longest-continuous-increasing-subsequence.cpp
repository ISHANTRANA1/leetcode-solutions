class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();

        if(n == 0)
            return 0;

        int cnt = 1;
        int maxi = 1;

        for(int i = 0; i < n-1; i++){
            if(nums[i] < nums[i+1]){
                cnt++;
            }
            else{
                cnt = 1;
            }

            maxi = max(maxi, cnt);
        }

        return maxi;
    }
};