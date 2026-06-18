class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count = 0;

        for (int num = low; num <= high; num++) {

            string s = to_string(num);

            int n = s.length();

            // Odd number of digits cannot be symmetric
            if (n % 2 != 0)
                continue;

            int leftSum = 0;
            int rightSum = 0;

            // Calculate both halves
            for (int i = 0; i < n / 2; i++) {
                leftSum += s[i] - '0';
            }

            for (int i = n / 2; i < n; i++) {
                rightSum += s[i] - '0';
            }

            if (leftSum == rightSum)
                count++;
        }

        return count;
    }
};