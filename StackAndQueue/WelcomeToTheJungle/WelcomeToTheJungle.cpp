// Hackerrank Problem: Welcome to the Jungle
// Contest: SDA Practice 4
// Link: https://www.hackerrank.com/contests/practice-4-sda/challenges/welcome-to-the-jungle
// Description:
// Zartan is standing in front of a sequence of trees. When he looks to the right,
// he can only see trees that are strictly taller than every tree before them.
// Using a decreasing monotonic stack, we scan the array from right to left and
// maintain only those trees that are visible (each new tree removes all smaller
// or equal trees behind it). For each position, the size of this stack represents
// how many trees Zartan would see if he stood there.
// We track the position from which he sees the maximum number of trees.
// Time complexity: O(n)
// Space complexity: O(n)

#include <cmath>
#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;

void monotonicStack(vector<int>& trees, stack<int>& result, int& posWithMostTrees)
{
    size_t currTreeCount = 1;

    for (int i = trees.size() - 1; i >= 0; i--)
    {
        while (!result.empty() && result.top() <= trees[i])
        {
            result.pop();
        }
        result.push(trees[i]);

        if (currTreeCount <= result.size())
        {
            currTreeCount = result.size();
            posWithMostTrees = i;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    vector<int> trees(n);

    for (int i = 0; i < n; i++)
    {
        std::cin >> trees[i];
    }

    stack<int> monotonicResult;
    int positionWithMostTrees = 0;
    monotonicStack(trees, monotonicResult, positionWithMostTrees);

    std::cout << positionWithMostTrees;

    return 0;
}