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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if (!n) {
            return NULL;
        }
        auto comp = [] (ListNode* l, ListNode* r) { return l->val > r->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comp)> min_heap(comp);
        ListNode *dummy = new ListNode(-1), *tail = dummy;
        for (ListNode* p : lists) {
            if (p) {
                min_heap.push(p);
            }
        }
        while (!min_heap.empty()) {
            ListNode *cur_min_node = min_heap.top();
            min_heap.pop();
            if (cur_min_node->next) {
                min_heap.push(cur_min_node->next);
            }
            tail->next = cur_min_node;
            tail = tail->next;
            tail->next = NULL;
        }
        ListNode *res = dummy->next;
        delete dummy;
        return res;
    }
};
