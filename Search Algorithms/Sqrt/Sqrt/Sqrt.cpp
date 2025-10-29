// LeetCode #69: Sqrt(x)
// Problem link: https://leetcode.com/problems/sqrtx/
// Approach: Binary Search
// Time complexity: O(log n)
// Space complexity: O(1)

#include <iostream>
using namespace std;

class Solution
{
public:
    int mySqrt(int x)
    {
        int left = 0, right = x;
        while (left <= right)
        {
            long mid = left + (right - left) / 2;
            if (mid * mid > x)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left - 1;
    }
};

int main() {
    Solution sol;
    cout << sol.mySqrt(4) << endl;  // Output: 2
    cout << sol.mySqrt(8) << endl;  // Output: 2
    cout << sol.mySqrt(16) << endl; // Output: 4
    return 0;
}
