class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        vector<int> prevSmaller(n), nextSmaller(n);
        vector<int> prevGreater(n), nextGreater(n);

        stack<int> st;

        // Previous Smaller or Equal
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }

            prevSmaller[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Strictly Smaller
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }

            nextSmaller[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Previous Greater or Equal
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            prevGreater[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // Next Strictly Greater
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            nextGreater[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long minSum = 0;
        long long maxSum = 0;

        for (int i = 0; i < n; i++) {

            long long leftMin = i - prevSmaller[i];
            long long rightMin = nextSmaller[i] - i;

            minSum += 1LL * nums[i] * leftMin * rightMin;


            long long leftMax = i - prevGreater[i];
            long long rightMax = nextGreater[i] - i;

            maxSum += 1LL * nums[i] * leftMax * rightMax;
        }

        return maxSum - minSum;
    }
};