class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int m = matrix.size();       // number of rows
        int n = matrix[0].size();    // number of columns

        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;


        while(top <= bottom && left <= right) {


            // 1. Traverse top row: left -> right
            for(int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;   // remove the top row


            // 2. Traverse right column: top -> bottom
            for(int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;   // remove the right column


            // 3. Traverse bottom row: right -> left
            // Check because the row may already be used
            if(top <= bottom) {

                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }

                bottom--;   // remove bottom row
            }


            // 4. Traverse left column: bottom -> top
            // Check because the column may already be used
            if(left <= right) {

                for(int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }

                left++;   // remove left column
            }
        }

        return ans;
    }
};