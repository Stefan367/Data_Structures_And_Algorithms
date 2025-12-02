// LeetCode problem: 242. Valid Anagram
// Difficulty: Easy
// Link: https://leetcode.com/problems/valid-anagram/
// Description: Determine if one string is an anagram of another using a frequency hash map.
// Time complexity: O(n)
// Space complexity: O(n)   // due to hash map usage (O(1) if only lowercase letters)

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }

        unordered_map<char, int> symbol_counter;
        for (int i = 0; i < s.size(); i++)
        {
            symbol_counter[s[i]]++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            if (--symbol_counter[t[i]] < 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;

    cout << boolalpha;

    cout << "Test 1 (\"anagram\", \"nagaram\") -> true: "
        << sol.isAnagram("anagram", "nagaram") << endl;

    cout << "Test 2 (\"rat\", \"car\") -> false: "
        << sol.isAnagram("rat", "car") << endl;

    cout << "Test 3 (\"aacc\", \"ccac\") -> false: "
        << sol.isAnagram("aacc", "ccac") << endl;

    return 0;
}
