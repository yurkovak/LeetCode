#include <iostream>
#include <memory>
#include <stack>
#include <string>
#include <vector>

#include "parse_input.h"


class Solution {
public:
    std::vector<int> inorderTraversal_rec(const std::shared_ptr<TreeNode>& root) {
        if (!root) return {};

        std::vector<int> inorder = inorderTraversal_rec(root->left);
        inorder.push_back(root->val);
        std::vector<int> right = inorderTraversal_rec(root->right);
	    inorder.insert(inorder.end(), right.begin(), right.end());

        return inorder;
    }

    std::vector<int> inorderTraversal_iter(const std::shared_ptr<TreeNode>& root) {
        if (!root) return {};

        std::vector<int> inorder;
        std::stack<const std::shared_ptr<TreeNode>> stack;
        stack.push(root);
        bool down = true;
        while (!stack.empty()){
            const std::shared_ptr<TreeNode> cur_node = stack.top();
            if (cur_node->left && down) stack.push(cur_node->left);
            else{
                stack.pop();
                inorder.push_back(cur_node->val);
                down = false;
                if (cur_node->right) {
                    stack.push(cur_node->right);
                    down = true;
                }
            }
        }

        return inorder;
    }
};


int main(){
    std::cout << "A tree represented by a space separated list level after level (null for a missing nodes): ";
    std::string line;
    std::getline(std::cin, line);

    std::shared_ptr<TreeNode> root = string2tree(line);
    std::vector<int> inorder_dfs = Solution().inorderTraversal_rec(root);
    std::cout << "Inorder traversal: (by recursion): ";
    for (auto v: inorder_dfs)
        std::cout << v << " ";
    std::cout << std::endl;

    std::vector<int> inorder_bfs = Solution().inorderTraversal_iter(root);
    std::cout << "Inorder traversal: (by iteration): ";
    for (auto v: inorder_bfs)
        std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}

