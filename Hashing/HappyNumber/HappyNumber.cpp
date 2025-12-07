// LeetCode problem: 202. Happy Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/happy-number/
// Description: Determine if a number is "happy". A number is happy if repeatedly replacing
//              it with the sum of the squares of its digits eventually reaches 1.
//              If a value repeats, a cycle is detected and the number is not happy.
// Time complexity: O(log n) per iteration, but overall bounded and very fast.
// Space complexity: O(log n) due to storing visited states.

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> cycle;
        int result = 0;

        while (true)
        {
            result = 0;

            while (n != 0)
            {
                result += (n % 10) * (n % 10);
                n /= 10;
            }

            n = result;

            if (n == 1)
                return true;

            if (cycle.contains(n))
                break;

            cycle.insert(n);
        }

        return false;
    }
};

int main()
{
    Solution sol;

    cout << boolalpha;

    cout << "Test 1: n = 19 -> true:  "
        << sol.isHappy(19) << endl;

    cout << "Test 2: n = 2 -> false: "
        << sol.isHappy(2) << endl;

    cout << "Test 3: n = 7 -> true:  "
        << sol.isHappy(7) << endl;

    cout << "Test 4: n = 20 -> false: "
        << sol.isHappy(20) << endl;

    return 0;
}
