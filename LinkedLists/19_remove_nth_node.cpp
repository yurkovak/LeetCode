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


// O(N)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // check if n  >= 0, if head isn't nullprt (guaranteed in the task)
        if (n == 0) return head;
        
        ListNode* cur = head;
        for (std::size_t i = 0; i < n; i++)
            cur = cur->next;
        
        // case of n = length, 0-th el. removal
        if (!cur) return head->next;
        
        ListNode* cur_m_n = head;
        for( ; cur->next; cur=cur->next, cur_m_n=cur_m_n->next);
        cur_m_n->next = cur_m_n->next->next;
        
        return head;
    }
};