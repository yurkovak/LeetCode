#include <vector>
#include <iostream>
#include <sstream>


// O(N)
class Solution {
public:
    bool canJump(std::vector<int>& nums) {
        if (!nums.size()) return true;
        
        std::size_t maxReach = 0;
        for (std::size_t i = 0; i < nums.size(); i++){
            if (maxReach >= nums.size() - 1) return true;
            if (nums.at(i) == 0 && maxReach <= i) return false;
            maxReach = std::max(maxReach, i + static_cast<std::size_t>(nums.at(i)));
        }
        
        return true;
    }
};


int main(){
    std::string line;
    std::cout << "Space separated array: ";
    std::getline(std::cin, line);

    std::vector<int> nums;
    int v;
    std::istringstream iss(line);
    while(iss >> v)
        nums.push_back(v);
    
    std::string answer = Solution().canJump(nums) ? "yes" : "no";
    std::cout << "Can jump: " << answer << std::endl;

    return 0;
}