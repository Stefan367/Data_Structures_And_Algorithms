// LeetCode problem: 383. Ransom Note
// Difficulty: Easy
// Link: https://leetcode.com/problems/ransom-note/
// Description: Determine if a ransom note can be constructed from the letters of a magazine using a hash map for counting.
// Time complexity: O(n + m)
// Space complexity: O(n)

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size())
            return false;

        unordered_map<char, int> letter_counter;
        for (int i = 0; i < magazine.size(); i++)
        {
            letter_counter[magazine[i]]++;
        }

        for (int i = 0; i < ransomNote.size(); i++)
        {
            letter_counter[ransomNote[i]]--;
        }

        for (auto& [key, value] : letter_counter)
        {
            if (value < 0)
                return false;
        }

        return true;
    }
};

int main()
{
    Solution sol;
    cout << boolalpha;

    cout << "Test 1 (\"a\", \"b\") -> false: "
        << sol.canConstruct("a", "b") << endl;

    cout << "Test 2 (\"aa\", \"ab\") -> false: "
        << sol.canConstruct("aa", "ab") << endl;

    cout << "Test 3 (\"aa\", \"aab\") -> true: "
        << sol.canConstruct("aa", "aab") << endl;

    return 0;
}
