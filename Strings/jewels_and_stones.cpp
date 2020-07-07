// O(J + S)


class Solution {
public:
    int numJewelsInStones(std::string J, std::string S) {
        std::unordered_set<char> jewels;
        for (std::size_t i = 0; i < J.size(); i++)
            jewels.insert(J[i]);
        
        unsigned sum = 0;
        for (std::size_t i = 0; i < S.size(); i++){
            if (jewels.find(S[i]) != jewels.end())
                sum++;
        }
            
        return sum;
    }
};