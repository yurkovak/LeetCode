#include <string>
#include <unordered_set>
#include <iostream>


// O(J + S)
class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        std::unordered_set<char> jewels;
        for (std::size_t i = 0; i < J.size(); i++)
            jewels.insert(J[i]);
        
        int sum = 0;
        for (std::size_t i = 0; i < S.size(); i++){
            if (jewels.find(S[i]) != jewels.end())
                sum++;
        }
            
        return sum;
    }
};


int main(){
    std::string J, S;
    std::cout << "J: ";
    std::cin >> J;
    std::cout << "S: ";
    std::cin >> S;

    std::cout << "Jewels in S: " << Solution().numJewelsInStones(J, S) << std::endl;
}