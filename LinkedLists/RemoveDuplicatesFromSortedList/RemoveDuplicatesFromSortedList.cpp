// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;

        ListNode* curr = head->next;
        ListNode* prev = head;

        while (curr != nullptr)
        {
            if (prev->val == curr->val)
            {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};