#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>


// O(N)
class Solution {
public:
    bool isValid(const std::string& s) {
        std::unordered_map<char, char> pair_p= {{'(', ')'}, {'{', '}'}, {'[', ']'}};
        std::stack<char> open_p;
        
        for (int i = 0; i < s.size(); i++){
            char cur_p = s.at(i);
            if (cur_p == '(' || cur_p == '{' || cur_p == '[')
                open_p.push(cur_p);
            else if (!open_p.empty() && cur_p == pair_p[open_p.top()])
                open_p.pop();
            else return false;
        }
            
        return open_p.empty();
    }
};


int main(){
    std::string s;
    std::cout << "String with characters '(', ')', '{', '}': ";
    std::cin >> s;

    std::cout << std::boolalpha;
    std::cout << "Is valid: " << Solution().isValid(s) << std::endl;
    return 0;
}