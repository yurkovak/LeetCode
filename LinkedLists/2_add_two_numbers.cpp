#include <string>
#include <iostream>
#include <sstream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void List2str(const ListNode* node, std::string& out){
    out = "";
    while (node)
    {
        out += std::to_string(node->val) + " ";
        node = node->next;
    }
}


ListNode* str2List(std::string line){
    ListNode head(0);
    ListNode* tail = &head;
    std::istringstream iss(line);
    int v;
    while (iss >> v)
    {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    
    return head.next;
}


// O(M + N)
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


int main(){
    std::string line;
    std::cout << "Space separated values of l1: ";
    std::getline(std::cin, line);
    ListNode* l1 = str2List(line);

    line = "";
    std::cout << "Space separated values of l2: ";
    std::getline(std::cin, line);
    ListNode* l2 = str2List(line);
    
    ListNode* l_sum = Solution().addTwoNumbers(l1, l2);
    std::string answer;
    List2str(l_sum, answer);
    std::cout << "Sum: " << answer << std::endl;
}