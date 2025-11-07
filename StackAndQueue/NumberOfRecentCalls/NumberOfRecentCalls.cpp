// LeetCode problem: 933. Number of Recent Calls
// Link: https://leetcode.com/problems/number-of-recent-calls/ 
// Description: Implementation of the RecentCounter class that counts recent requests in the past 3000 milliseconds using a queue.


#include <queue>
using namespace std;

class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {

    }

    int ping(int t) {
        int pastT = t - 3000;
        q.push(t);

        while (!q.empty())
        {
            if (q.front() < pastT)
            {
                q.pop();
            }
            else
            {
                break;
            }
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
