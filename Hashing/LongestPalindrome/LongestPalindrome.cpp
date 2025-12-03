// LeetCode problem: 409. Longest Palindrome
// Difficulty: Easy
// Link: https://leetcode.com/problems/longest-palindrome/
// Description: Find the length of the longest palindrome that can be built using character counts.
// Time complexity: O(n)
// Space complexity: O(n)

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> letters_count;

        for (char& ch : s)
        {
            letters_count[ch]++;
        }

        int longest = 0;
        bool hasOdd = false;
        for (auto& [letter, count] : letters_count)
        {
            if (count % 2 == 0)
            {
                longest += count;
            }
            else
            {
                longest += (count / 2) * 2;
                hasOdd = true;
            }
        }

        if (hasOdd)
            longest += 1;

        return longest;
    }
};

int main()
{
    Solution sol;

    cout << sol.longestPalindrome("abccccdd") << " (expected 7)" << endl;
    cout << sol.longestPalindrome("a") << " (expected 1)" << endl;
    cout << sol.longestPalindrome("ccc") << " (expected 3)" << endl;
    cout << sol.longestPalindrome("bananas") << " (expected 5 or 7 depending on arrangement)" << endl;

    return 0;
}