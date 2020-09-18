#include <vector>
#include <iostream>
#include <sstream>


// O(N)
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (!nums.size()) return 0;
        
        int prev = nums.at(0);
        int max_sum = prev;
        int cur_sum;
        for (std::size_t i = 1; i < nums.size(); i++){
            cur_sum = prev + nums.at(i);
            prev = (cur_sum > nums.at(i)) ? cur_sum : nums.at(i);
            max_sum = (max_sum > prev) ? max_sum : prev;
        }
        
        return max_sum;
    }
};



int main(){
    std::cout << "Space separated array: ";
    std::string line;
    std::getline(std::cin, line);
    
    // split by space
    std::vector<int> nums;
    int v;
    std::istringstream iss(line);
    while (iss >> v) {    
        nums.push_back(v);
    }
    
    std::cout << "Sorted colors: " << Solution().maxSubArray(nums) << std::endl;

    return 0;
}