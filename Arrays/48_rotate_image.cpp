#include <vector>
#include <iostream>
#include <string>
#include <sstream>


void printMatrix(std::vector<std::vector<int>>& matrix){
    for (std::vector<int> row : matrix){
        for (int v : row)
            std::cout << v << ' ';

        std::cout << std::endl;
    }
}


// O(n^2)
class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        
        int a, b, c, d;
        int *a_p, *b_p, *c_p, *d_p;
        int r_circle;
        for (int circle = 0; circle < n/2; circle++){
            r_circle = n - circle - 1;
            for (int i = circle; i < n - circle - 1; i++){
                a_p = &matrix.at(circle).at(i);
                b_p = &matrix.at(i).at(r_circle);
                c_p = &matrix.at(r_circle).at(n - i - 1);
                d_p = &matrix.at(n - i - 1).at(circle);
                
                a = *a_p;
                b = *b_p; *b_p = a;
                c = *c_p; *c_p = b;
                d = *d_p; *d_p = c;
                *a_p = d;
            }
        }
    }
};


int main(){
    std::cout << "Matrix row by row:" << std::endl;
    
    int v;
    std::vector<int> row;
    std::string line;
    std::istringstream ss;

    // get first row and check n
    std::getline(std::cin, line);
    ss.str(line);
    while (ss >> v)
        row.push_back(v);
    int n = row.size();

    // get the rest of the rows
    std::vector <std::vector<int>> matrix(n);
    matrix.at(0) = row;
    for (int i = 1; i < n; i++){
        row = {};
        std::getline(std::cin, line);
        ss.clear();
        ss.str(line);
        while (ss >> v)
            row.push_back(v);

        if (row.size() > n)
            throw std::runtime_error("Should have been " + std::to_string(n) + " values");
        else matrix.at(i) = row;
    }

    Solution().rotate(matrix);
    std::cout << "Rotated:" << std::endl;
    printMatrix(matrix);
}