// LeetCode problem: 20. Valid Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Description: Implementation of the Valid Parentheses solution using a stack.
// Time complexity: O(n), Space complexity: O(n)

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            {
                st.push(s[i]);
            }
            else
            {
                if (st.empty()) return false;

                if ((s[i] == ')' && st.top() == '(')
                    || (s[i] == ']' && st.top() == '[')
                    || (s[i] == '}' && st.top() == '{'))
                {
                    st.pop();
                }
                else return false;
            }
        }

        return st.size() == 0;
    }
};
