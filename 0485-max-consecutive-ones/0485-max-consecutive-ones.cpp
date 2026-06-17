class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi=0;
        int cut=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]==1){
                cut++;
                maxi=max(maxi,cut);
            }
            else{
                cut =0;
            }
        }
        return maxi;
        
    }
};