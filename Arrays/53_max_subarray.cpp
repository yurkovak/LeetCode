// O(N)
class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        if (!nums.size()) return NULL;
        
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