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




int main(){
    std::string line;
    std::cout << "Space separated values of l: ";
    std::getline(std::cin, line);
    ListNode* l = str2List(line);

    int n;
    std::cout << "N: ";
    std::cin >> n;
    
    ListNode* l_res = Solution().removeNthFromEnd(l, n);
    std::string answer;
    List2str(l_res, answer);
    std::cout << "After removal: " << answer << std::endl;
}
