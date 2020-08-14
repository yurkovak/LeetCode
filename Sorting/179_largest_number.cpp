#include <string>
#include <vector>
#include <iostream>
#include <sstream>


// O(SNlogN)
class Solution {
public:
    std::string largestNumber(const std::vector<int>& nums) {
        if (nums.size() == 0)
            return "";
        
        // O(SN) space
        std::vector<std::string> nums_str;
        nums_str.reserve(nums.size());
        for (int v : nums)
            nums_str.push_back(std::to_string(v));
        
        // O(S)
        auto correct_order = [](std::string& l, std::string& r){return l + r > r + l;};
        // O(SNlogN)
        std::sort(nums_str.begin(), nums_str.end(), correct_order);
        
        // O(SN) time
        std::string longest = "";
        for (std::string v : nums_str) 
            longest += v;
        
        longest = longest.at(0) == '0' ? "0" : longest;
        return longest;
    }
};


int main(){
    std::cout << "Space separated numbers: ";
    std::string line;
    std::getline(std::cin, line);
    
    // split by space
    std::vector<int> nums;
    int c;
    std::istringstream iss(line);
    while (iss >> c) {    
        nums.push_back(c);
    }
    
    std::cout << "Largest number: " << Solution().largestNumber(nums) << std::endl;
}