// LeetCode #278: First Bad Version
// Approach: Binary Search on Answer
// Time complexity: O(log n)
// Space complexity: O(1)

#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n, ans = n;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (isBadVersion(mid))
            {
                ans = mid;
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n1 = 5;
    int badVersion = 4;
    cout << "Test 1: n = " << n1 << ", bad = " << badVersion
        << sol.firstBadVersion(n1) << endl;

    int n2 = 1;
    badVersion = 1;
    cout << "Test 2: n = " << n2 << ", bad = " << badVersion
        << sol.firstBadVersion(n2) << endl;

    int n3 = 10;
    badVersion = 6;
    cout << "Test 3: n = " << n3 << ", bad = " << badVersion
        << sol.firstBadVersion(n3) << endl;

    return 0;
}
