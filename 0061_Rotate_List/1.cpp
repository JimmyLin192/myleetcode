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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode * cur_node = head;
        int count = 0;
        while (cur_node != NULL) {
            count ++;
            cur_node = cur_node->next;
        }
        if (count == 0 || (k %= count) == 0) {
            return head;
        }
        ListNode *first = head, *second = head, *ans;
        for (int i = 0; i < k; i ++) {
            first = first->next;
        }
        while (first->next != NULL) {
            first = first->next;
            second = second->next;
        }
        ans = second->next;
        second->next = NULL;
        first->next = head;
        return ans;
    }
};
