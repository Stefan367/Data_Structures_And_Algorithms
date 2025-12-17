// HackerRank problem: Jesse and Cookies
// Difficulty: Easy/Medium
// Link: https://www.hackerrank.com/challenges/jesse-and-cookies/problem
// Description: Combine the two least sweet cookies until all have sweetness >= k, or return -1.
// Time complexity: O(n log n)
// Space complexity: O(n)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int cookies(int k, vector<int> A) {
    priority_queue<int, vector<int>, greater<int>> pq(A.begin(), A.end());
    long long firstCookie, secondCookie;
    int steps = 0;

    while (pq.top() < k)
    {
        if (pq.size() <= 1)
            return -1;

        firstCookie = pq.top();
        pq.pop();
        secondCookie = 2 * pq.top();
        pq.pop();

        pq.push(firstCookie + secondCookie);
        steps++;
    }

    return steps;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << cookies(k, A) << "\n";
    return 0;
}
