#include <string>
#include <iostream>
#include <sstream>

#include "parse_input.h"


// O(N)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr){
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }
};


int main(){
    std::string line;
    std::cout << "Space separated values of l: ";
    std::getline(std::cin, line);
    ListNode* l = str2List(line);

    ListNode* l_res = Solution().reverseList(l);
    std::string answer;
    List2str(l_res, answer);
    std::cout << "Reversed: " << answer << std::endl;

    return 0;
}