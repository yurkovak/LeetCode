#include <iostream>
#include <vector>


class Solution {
public:
    // O(logk)
    int findMinFibonacciNumbers(int k) {
        if (k <= 1) return 1;

        // iterate right before the closest fib num to k is found
        int prev_prev = 0, prev = 1;
        while (prev <= k){
            std::swap(prev_prev, prev);
            prev += prev_prev;
        }

        // iterate down and collect k as a sum of fib nums
        int residual = k, n_nums = 0;
        while (residual > 0){
            if (residual - prev >= 0){
                residual -= prev;
                n_nums++;
            }
            if (residual == 1) return ++n_nums;

            std::swap(prev_prev, prev);
            prev_prev -= prev;
        }

        return n_nums;
    }

    // O(logk), more readable, but O(logK) space
    int _findMinFibonacciNumbers(int k) {
        if (k <= 1) return 1;

        std::vector<int> nums = {0, 1};
        int size = 2;
        while (nums.at(size - 1) < k){
            nums.push_back(nums.at(size - 1) + nums.at(size - 2));
            size++;
        }

        int residual = k, n_nums = 0;
        for (int i = size - 1; i >= 0 && residual > 0; i--){
            if (residual - nums.at(i) >= 0){
                residual -= nums.at(i);
                n_nums++;
                // skip one, cause two consecutive nums cannot be picked
                // since if needed their sum should be picked otherwise
                i--;
            }
            if (residual == 1) return ++n_nums;
        }
        return n_nums;
    }
};


int main(){
    int k;
    std::cout << "k = ";
    std::cin >> k;
    if (k < 0) throw std::runtime_error("Provide a valid number");

    std::cout << "Minimum number of Fibonacci numbers to sum into k: " << Solution().findMinFibonacciNumbers(k) << std::endl;
}
