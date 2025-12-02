// LeetCode problem: 13. Roman to Integer
// Difficulty: Easy
// Link: https://leetcode.com/problems/roman-to-integer/
// Description: Convert a Roman numeral string to its corresponding integer value.
// Time complexity: O(n)
// Space complexity: O(1)  // constant extra space for the map

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romans = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;
        auto prev = romans.find('I');
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (romans[s[i]] < prev->second)
            {
                result -= romans[s[i]];
            }
            else
            {
                result += romans[s[i]];
            }
            prev = romans.find(s[i]);
        }
        return result;
    }
};

int main()
{
    Solution sol;

    string s1 = "III";     // 3
    string s2 = "LVIII";   // 58
    string s3 = "MCMXCIV"; // 1994

    cout << sol.romanToInt(s1) << " (expected 3)" << endl;
    cout << sol.romanToInt(s2) << " (expected 58)" << endl;
    cout << sol.romanToInt(s3) << " (expected 1994)" << endl;

    return 0;
}