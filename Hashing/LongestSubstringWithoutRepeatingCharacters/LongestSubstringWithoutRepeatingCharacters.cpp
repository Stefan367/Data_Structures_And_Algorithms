// LeetCode problem: 3. Longest Substring Without Repeating Characters
// Difficulty: Medium
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Description: Sliding window + hash map to track last seen positions of characters.
// Time complexity: O(n)
// Space complexity: O(k) where k is the alphabet size (<= n)

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_index;
        int left = 0, maxLength = 0;

        for (int i = 0; i < s.size(); i++)
        {
            auto iter = last_index.find(s[i]);

            if (iter != last_index.end() && iter->second >= left)
            {
                left = last_index[s[i]] + 1;
            }
            last_index[s[i]] = i;

            maxLength = max(maxLength, i - left + 1);
        }

        return maxLength;
    }
};

int main()
{
    Solution sol;

    cout << sol.lengthOfLongestSubstring("abcabcbb") << " (expected 3)" << endl;
    cout << sol.lengthOfLongestSubstring("bbbbb") << " (expected 1)" << endl;
    cout << sol.lengthOfLongestSubstring("pwwkew") << " (expected 3)" << endl;
    cout << sol.lengthOfLongestSubstring("") << " (expected 0)" << endl;
    cout << sol.lengthOfLongestSubstring(" ") << " (expected 1)" << endl;
    cout << sol.lengthOfLongestSubstring("dvdf") << " (expected 3)" << endl;

    return 0;
}