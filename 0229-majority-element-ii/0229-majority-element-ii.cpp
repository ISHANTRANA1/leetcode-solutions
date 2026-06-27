class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        vector<int> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int cnt = 1;

        for(int i = 1; i <= n; i++){

            if(i < n && nums[i] == nums[i-1]){
                cnt++;
            }
            else{

                if(cnt > n/3){
                    ans.push_back(nums[i-1]);
                }

                cnt = 1; 
            }
        }

        return ans;
    }
};