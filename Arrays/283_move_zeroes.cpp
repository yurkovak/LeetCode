#include <iostream>
#include <sstream>
#include <string>
#include <vector>


// O(N)
class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int frst_zero = -1;
        
        for (int i = 0; i < nums.size(); i++){
            if (nums.at(i) == 0 && frst_zero == -1)
                frst_zero = i;
            else if (nums.at(i) != 0 && frst_zero != -1){
                std::swap(nums.at(i), nums.at(frst_zero));
                frst_zero++;
            }
        }
        
    }
};


int main(){
    std::cout << "Space separated array: ";
    std::string line;
    std::getline(std::cin, line);

    std::istringstream ss(line);
    int v;
    std::vector<int> nums;
    while (ss >> v)
        nums.push_back(v);

    Solution().moveZeroes(nums);
    std::cout << "Zeros moved: ";
    for (int v : nums)
        std::cout << v << ' ';
    std::cout << std::endl;
}