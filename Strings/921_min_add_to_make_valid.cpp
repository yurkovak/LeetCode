#include <iostream>
#include <string>


// O(N)
class Solution{
public:
    int minAddToMakeValid(const std::string& S) {
        unsigned open = 0, closed = 0;
        
        for (char cur_p : S){
            if (cur_p == '(') open++;
            else if (cur_p == ')' && open > 0) open--;
            else closed++;
        }
        return open + closed;
    }
};


int main(){
    std::string s;
    std::cout << "String with characters '(', ')', '{', '}': ";
    std::cin >> s;

    std::cout << std::boolalpha;
    std::cout << "Minimum add to make parentheses valid: " << Solution().minAddToMakeValid(s) << std::endl;
    return 0;
}
