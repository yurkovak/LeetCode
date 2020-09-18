#include <iostream>
#include <string>
#include <vector>

#include "parse_input.h"


class Solution {
public:
    std::vector<int> inorderTraversal_DFS(const TreeNode* root) {
        if (!root) return {};
        
        std::vector<int> inorder = inorderTraversal_DFS(root->left);
        inorder.push_back(root->val);
        std::vector<int> right = inorderTraversal_DFS(root->right);
	    inorder.insert(inorder.end(), right.begin(), right.end());

        return inorder;
    }
};


int main(){
    std::cout << "A tree represented by a space separated list level after level (null for a missing nodes): ";
    std::string line;
    std::getline(std::cin, line);

    TreeNode* root = string2tree(line);
    std::vector<int> inorder = Solution().inorderTraversal_DFS(root);
    std::cout << "Inorder traversal: (by DFS): ";
    for (auto v: inorder)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}

