#include <vector>
#include <iostream>
#include <sstream>


// O(N)
class Solution {
public:
    void sortColors(std::vector<int>& nums) {
        std::vector<int> right_most = {-1, -1, -1};
        
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0) {
                std::swap(nums[right_most[0] + 1], nums[i]);
                // repeating code for readability, to separate 0/1/2 cases
                if (nums[i] == 1)
                    std::swap(nums[right_most[1] + 1], nums[i]);
                right_most[0]++; right_most[1]++; right_most[2]++;
            }
            else if (nums[i] == 1){
                std::swap(nums[right_most[1] + 1], nums[i]);
                right_most[1]++; right_most[2]++;
            }
            else{
                right_most[2]++;
            }
        }
        
    }
};


int main(){
    std::cout << "Space separated colors: ";
    std::string line;
    std::getline(std::cin, line);
    
    // split by space
    std::vector<int> nums;
    int c;
    std::istringstream iss(line);
    while (iss >> c) {    
        nums.push_back(c);
    }
    
    Solution().sortColors(nums);
    std::cout << "Sorted colors: ";
    for (auto v: nums) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}