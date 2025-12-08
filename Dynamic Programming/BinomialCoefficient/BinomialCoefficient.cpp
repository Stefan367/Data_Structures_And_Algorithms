// Problem: Compute Binomial Coefficient C(n, k)
// Description: Uses top-down dynamic programming (memoization) based on Pascal's identity:
//              C(n, k) = C(n-1, k-1) + C(n-1, k), with bases C(n, 0) = C(n, n) = 1.
// Time complexity: O(n * k)   (each state (n, k) is computed at most once)
// Space complexity: O(n * k)  (for the memoization table)

#include <iostream>
#include <vector>
using namespace std;

int getnCk(int n, int k, vector<vector<int>>& memo)
{
    if (k > n)
        return 0;

    if (k == 0 || k == n)
        return 1;

    if (memo[n][k] != -1)
        return memo[n][k];

    return memo[n][k] = getnCk(n - 1, k - 1, memo) + getnCk(n - 1, k, memo);
}

int binomialCoeff(int n, int k)
{
    vector<vector<int>> memo(n + 1, vector<int> (k + 1, -1));
    return getnCk(n, k, memo);
}

int main()
{
    int n = 8, k = 5;
    cout << binomialCoeff(n, k);
    return 0;
}
