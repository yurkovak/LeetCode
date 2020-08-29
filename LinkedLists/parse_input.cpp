#include <sstream>
#include "parse_input.h"


void List2str(const ListNode* node, std::string& out){
    out = "";
    while (node)
    {
        out += std::to_string(node->val) + " ";
        node = node->next;
    }
}


ListNode* str2List(const std::string line){
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


