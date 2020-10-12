#include <string>
#include <iostream>
#include <sstream>

#include "parse_input.h"


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

    return 0;
}
