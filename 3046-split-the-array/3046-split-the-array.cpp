class Solution {
public:
    bool isPossibleToSplit(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> freq;

        for(int x=0; x<n; x++){

            freq[nums[x]]++;

            if(freq[nums[x]] > 2){
                return false;
            }
        }

        return true;
    }
};