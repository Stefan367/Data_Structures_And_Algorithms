// https://leetcode.com/problems/middle-of-the-linked-list/
// Middle of the Linked List — LeetCode Problem

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;

            if (fast->next != nullptr)
                fast = fast->next;
        }

        return slow;
    }
};