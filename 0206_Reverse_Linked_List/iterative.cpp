/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head->next)) {
            return head;
        }
        ListNode *dummy = new ListNode(-1), *cur = head->next;
        dummy->next = head;
        while (cur) {
            ListNode *temp = cur->next;
            head->next = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = temp;
        }
        head = dummy->next;
        delete dummy;
        return head;
    }
};
