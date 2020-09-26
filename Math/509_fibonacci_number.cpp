#include <iostream>


// O(N)
class Solution {
public:
    int fib(int N) {
        if (N <= 1) return N;

        int prev_prev = 0, prev = 1;
        for (int i = 2; i <= N; i++){
            int cur = prev_prev + prev;
            prev_prev = prev;
            prev = cur;
        }

        return prev;
    }
};


int main(){
    std::cout << "n = ";
    int N;
    std::cin >> N;

    std::cout << "Fibonacci number, F(n) = " << Solution().fib(N) << std::endl;
}

