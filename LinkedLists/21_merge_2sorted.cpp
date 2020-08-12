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


// O(N + M)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode merge = ListNode();
        ListNode* cur = &merge;
        
        while (l1 && l2){
            if (l1->val <= l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        
        cur->next = l1? l1 : l2;
        return merge.next;
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
    
    ListNode* l_res = Solution().mergeTwoLists(l1, l2);
    std::string answer;
    List2str(l_res, answer);
    std::cout << "Sorted: " << answer << std::endl;
}