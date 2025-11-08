// LeetCode problem: 844. Backspace String Compare
// Link: https://leetcode.com/problems/backspace-string-compare/
// Description: Compares two strings after applying backspace operations using helper function and stacks.
// Time complexity: O(n + m)
// Space complexity: O(n + m)

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    stack<char> processString(const string& str)
    {
        stack<char> result;
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] != '#')
            {
                result.push(str[i]);
            }
            else
            {
                if (!result.empty()) result.pop();
            }
        }
        return result;
    }

    bool backspaceCompare(string s, string t) {
        stack<char> st1 = processString(s);
        stack<char> st2 = processString(t);

        if (st1.size() != st2.size())
            return false;

        while (st1.size())
        {
            if (st1.top() != st2.top())
                return false;

            st1.pop();
            st2.pop();
        }

        return true;
    }
};
