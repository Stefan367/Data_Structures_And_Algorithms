// LeetCode #875: Koko Eating Bananas
// Approach: Binary Search on Answer
// Time complexity: O(n log m)
// Space complexity: O(1)

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check(vector<int>& piles, long long h, long long k)
    {
        long long hours = 0;

        for (auto& pile : piles)
        {
            hours += (pile + k - 1) / k;
        }
        return h >= hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long left = 1, right = INT_MIN, ans = -1;

        for (auto& pile : piles)
        {
            right = max(right, (long long)pile);
        }

        while (left <= right)
        {
            long long mid = left + (right - left) / 2;

            if (check(piles, h, mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return (int)ans;
    }
};
