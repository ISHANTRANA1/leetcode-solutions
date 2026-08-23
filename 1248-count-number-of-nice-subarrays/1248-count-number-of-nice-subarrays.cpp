class Solution {
public:
long long atMost(vector<int>& nums, int k){
    int left =0;
    int odd=0;
    long long  ans=0;
    for(int right =0; right<nums.size();right++){
        //add current element
        if(nums[right]%2 ==1){
            odd++;
        }
        while(odd>k){
                    if(nums[left]%2 ==1){
            odd--;
        }
        left++;

        }
 //no. of valid subarrays ending at right 
 ans +=right -left +1;
    }
    return ans;

}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums,k)- atMost(nums,k-1);
    }
};