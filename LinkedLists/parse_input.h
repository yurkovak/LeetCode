#ifndef PARSE_INPUT_H    
#define PARSE_INPUT_H

#include <string>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void List2str(const ListNode* node, std::string& out);


ListNode* str2List(const std::string line);


#endif