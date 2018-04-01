/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {
            return NULL;
        }
        unordered_map<RandomListNode*, RandomListNode*> mp;
        mp[NULL] = NULL;
        RandomListNode *cur = head, *dummy = new RandomListNode(-1), *tail = dummy;
        while (cur) {
            tail->next = new RandomListNode(cur->label);
            tail = tail->next;
            mp[cur] = tail;
            cur = cur->next;
        }
        cur = head;
        RandomListNode *copy_cur = dummy->next;
        while (cur && copy_cur) {
            copy_cur->random = mp[cur->random];
            cur = cur->next, copy_cur = copy_cur->next;
        }
        copy_cur = dummy->next;
        delete dummy;
        return copy_cur;
    }
};

