class Solution {
public:
    vector<int> beautifulArray(int n) {
       if (n==1)
       return {1};
       vector<int> smaller =beautifulArray((n+1)/2);
       vector<int> ans;
       //create odd numbers
       for(int x:smaller){
        int odd =2*x-1;
        if(odd<=n){
            ans.push_back(odd);
        }
       }
       for(int x:smaller){
        int even =2*x;
        if(even<=n)
        ans.push_back(even);
       }
       return ans;
    }
};