#include <iostream>
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


// O(n), where n is num digits in the longest of l1, l2
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // must fill next of a prev node with a new node only when a new digit exists & is known
        // keep as nullptr otherwise
        ListNode prehead(0);
        ListNode* cur_node = &prehead;
        unsigned carrier = 0, cur_sum = 0;
        
        while (l1 || l2 || carrier){
            cur_sum = carrier + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
            
            cur_node->next = new ListNode(cur_sum % 10);
            cur_node = cur_node->next;
            carrier = cur_sum/10;
        }
        
        return prehead.next;
    }
    
};