// LeetCode problem 19. Remove Nth Node From End of List
// Link - https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Complexity: O(n) time, O(1) space

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;

        ListNode* curr = head;
        ListNode* elToDelete = head;

        while (n)
        {
            curr = curr->next;
            n--;

            if (curr == nullptr)
            {
                ListNode* temp = head;
                head = head->next;
                delete temp;
                return head;
            }
        }

        while (curr->next != nullptr)
        {
            elToDelete = elToDelete->next;
            curr = curr->next;
        }

        ListNode* temp = elToDelete->next;
        elToDelete->next = elToDelete->next->next;
        delete temp;

        return head;
    }
};

// Example usage (optional):
// int main() {
//     // Example: [1,2,3,4,5], n = 2
//     ListNode* n5 = new ListNode(5);
//     ListNode* n4 = new ListNode(4, n5);
//     ListNode* n3 = new ListNode(3, n4);
//     ListNode* n2 = new ListNode(2, n3);
//     ListNode* n1 = new ListNode(1, n2);
//
//     Solution s;
//     ListNode* res = s.removeNthFromEnd(n1, 2);
//
//     while (res) {
//         cout << res->val << " ";
//         res = res->next;
//     }
//     cout << endl;
// }
