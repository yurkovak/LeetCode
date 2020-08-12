# include <vector>
#include <string>
#include <iostream>


// O(N)
class Solution {
public:
    std::string getHint(std::string secret, std::string guess) {
        std::vector<unsigned> secret_set(10);
        for (std::size_t i = 0; i < secret.size(); i++)
            secret_set[char2int(secret[i])]++;
        
        unsigned bulls = 0, cows = 0;
        char g, s;
        for (std::size_t i = 0; i < guess.size(); i++){
            g = guess[i]; s = secret[i];
            if (g == s && secret_set[char2int(g)] > 0) { 
                bulls++;
                secret_set[char2int(g)]--;
            }
        }
        
        for (std::size_t i = 0; i < guess.size(); i++){
            g = guess[i]; s = secret[i];
            if (g != s && secret_set[char2int(g)] > 0) {
                cows++;
                secret_set[char2int(g)]--;
            }
        }
        
        return std::to_string(bulls) + "A" + std::to_string(cows) + "B";
    }
    
protected:
    int char2int(const char c){
        return c - '0';
    }
};


int main(){
    std::string secret, guess;
    std::cout << "secret: ";
    std::cin >> secret;
    std::cout << "guess: ";
    std::cin >> guess;

    std::cout << "Hint: " << Solution().getHint(secret, guess) << std::endl;
}