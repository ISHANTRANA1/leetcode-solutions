class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
        const int MOD =1e9 + 7;
        vector<int> prev(n);
        vector<int> next(n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                prev[i]=-1;
            }
            else{
                prev[i]=st.top();
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                next[i]=n;
            }
            else{
                next[i]=st.top();
            }
            st.push(i);
        }
        long long sum=0;
        for(int i =0; i<n;i++){
            long long left =i- prev[i];
            long long right =next[i]-i;
            long long contribution=(left*right)%MOD;
            contribution =(contribution*arr[i]%MOD);
            sum=(sum+contribution)%MOD;
        }
        return sum;
    }
};