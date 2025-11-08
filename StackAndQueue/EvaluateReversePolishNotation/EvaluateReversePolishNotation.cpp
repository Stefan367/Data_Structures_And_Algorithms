// LeetCode problem: 150. Evaluate Reverse Polish Notation
// Link: https://leetcode.com/problems/evaluate-reverse-polish-notation/
// Description: Implementation of RPN (Reverse Polish Notation) expression evaluation using a stack.
// Time complexity: O(n)
// Space complexity: O(n)

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(int stackFirstTop, int stackSecondTop, string op)
    {
        if (op == "+")
            return stackSecondTop + stackFirstTop;

        else if (op == "-")
            return stackSecondTop - stackFirstTop;

        else if (op == "*")
            return stackSecondTop * stackFirstTop;

        else
            return stackSecondTop / stackFirstTop;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); ++i)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                st.push(stoi(tokens[i]));
            }
            else
            {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();

                int result = calculate(n1, n2, tokens[i]);
                st.push(result);
            }
        }
        return st.top();
    }
};
