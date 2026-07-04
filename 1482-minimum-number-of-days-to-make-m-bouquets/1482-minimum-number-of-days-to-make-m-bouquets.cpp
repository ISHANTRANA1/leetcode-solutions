class Solution {
public:
   bool canMake(vector<int>& bloomDay, int day, int m, int k) {
        int bouquets = 0;
        int flowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                flowers++;

                if (flowers == k) {
                    bouquets++;
                    flowers = 0;   // Flowers are used, start a new bouquet
                }
            } else {
                flowers = 0;       // Adjacency breaks
            }
        }

        return bouquets >= m;
    }
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long requiredFlowers = 1LL * m * k;

        // Impossible case
        if (requiredFlowers > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMake(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;   // Try for a smaller day
            } else {
                low = mid + 1;    // Need more days
            }
        }

        return ans;
        
    }
};