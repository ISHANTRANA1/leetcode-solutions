class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        unordered_map<char, int> mp;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {

            // If character already exists in current window
            if (mp.find(s[right]) != mp.end() && mp[s[right]] >= left) {
                left = mp[s[right]] + 1;
            }

            // Store latest index
            mp[s[right]] = right;

            // Update maximum length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};