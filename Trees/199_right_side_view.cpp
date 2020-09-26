#include <iostream>
#include <stack>
#include <vector>

#include "parse_input.h"


// O(N)
class Solution {
public:
    std::vector<int> rightSideView(const TreeNode_p& root) {
        std::vector<int> result;

        std::stack <std::pair<TreeNode_p, int>> sides;
        sides.push({root, 0});
        int max_depth = 0;
        while (!sides.empty()){
            std::pair<TreeNode_p, int> cur_node_d = sides.top();
            TreeNode_p cur_node = cur_node_d.first;
            int cur_depth = cur_node_d.second;
            sides.pop();

            while (cur_node){
                cur_depth++;
                if (cur_depth > max_depth) {
                    result.push_back(cur_node->val);
                    max_depth++;
                }
                if (cur_node->left) sides.push({cur_node->left, cur_depth});

                cur_node = cur_node->right;
            }
        }

        return result;
    }
};


int main(){
    std::string line;
    std::cout << "A tree represented by a space separated list level after level (null for a missing nodes): ";
    std::getline(std::cin, line);

    std::shared_ptr<TreeNode> root = string2tree(line);
    std::vector<int> right_side = Solution().rightSideView(root);

    std::cout << "Right side view: " << std::endl;
    for (int val : right_side) {
        std::cout << val << ' ';
    }
    std::cout << std::endl;

    return 0;
}