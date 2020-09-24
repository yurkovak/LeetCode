#include <iostream>
#include <queue>
#include <string>
#include <vector>

#include "parse_input.h"


// O(N)
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(const std::shared_ptr<TreeNode>& root) {
        if (!root) return {};
        std::vector<std::vector<int>> res;

        std::queue <std::shared_ptr<TreeNode>> level_queue;
        level_queue.push(root);
        while (!level_queue.empty()){
            int level_size = level_queue.size();
            std::vector<int> level = {};
            for (int i = 0; i < level_size; i++){
                const std::shared_ptr<TreeNode> cur_node = level_queue.front();
                level_queue.pop();
                level.push_back(cur_node->val);
                if (cur_node->left) level_queue.push(cur_node->left);
                if (cur_node->right) level_queue.push(cur_node->right);
            }
            res.push_back(level);
        }

        return res;
    }
};


int main(){
    std::string line;
    std::cout << "A tree represented by a space separated list level after level (null for a missing nodes): ";
    std::getline(std::cin, line);

    std::shared_ptr<TreeNode> root = string2tree(line);
    std::vector<std::vector<int>> level_order = Solution().levelOrder(root);

    std::cout << "Level order traversal: " << std::endl;
    for (std::vector<int> level : level_order){
        for (int val : level) {
            std::cout << val << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}