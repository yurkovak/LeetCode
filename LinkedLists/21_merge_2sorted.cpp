#include <string>
#include <iostream>
#include <sstream>

#include "parse_input.h"


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

    return 0;
}