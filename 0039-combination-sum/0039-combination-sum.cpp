class Solution {
public:
    void solve(int index, int target, vector<int>& candidates,
               vector<int>& current, vector<vector<int>>& ans) {
        
        // Base case
        if (target == 0) {
            ans.push_back(current);
            return;
        }

        if (index == candidates.size()) {
            return;
        }

        // Take the current element
        if (candidates[index] <= target) {
            current.push_back(candidates[index]);

            // Same index because we can take the number again
            solve(index, target - candidates[index], candidates, current, ans);

            // Backtrack
            current.pop_back();
        }

        // Don't take current element, move to next
        solve(index + 1, target, candidates, current, ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;

        solve(0, target, candidates, current, ans);

        return ans;
    }
};