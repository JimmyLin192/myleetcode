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
    pair<ListNode*, ListNode*> reverseListHelper(ListNode* head) {
        if (!(head->next)) {
            return make_pair(head, head);
        }
        auto p = reverseListHelper(head->next);
        p.second->next = head;
        head->next = NULL;
        return make_pair(p.first, head);
    }
    ListNode* reverseList(ListNode* head) {
        if (!head) {
            return NULL;
        }
        auto p = reverseListHelper(head);
        return p.first;
    }
};
