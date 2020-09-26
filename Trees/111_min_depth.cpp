#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <queue>

#include "parse_input.h"


class Solution {
public:
    // DFS: O(N) time, O(logN) space
    int minDepth_DFS(const TreeNode_p& root) {
        if (!root)
            return 0;

        int depth_left = minDepth_DFS(root->left);
        int depth_right = minDepth_DFS(root->right);

        if (depth_left > 0 && depth_right > 0)
            return 1 + std::min(depth_left, depth_right);
        else return 1 + std::max(depth_left, depth_right);
    }

    // BFS: O(N) time, O(N) space
    int minDepth_BFS(const TreeNode_p& root) {
        std::queue<const TreeNode_p> layer;
        if (root) layer.push(root);

        int count = 0;
        while(!layer.empty()){
            int layer_size = layer.size();
            for (int i = 0; i < layer_size; i++){
                const TreeNode_p cur_node = layer.front();
                layer.pop();
                if (!cur_node->left && !cur_node->right) return ++count;
                if(cur_node->left) layer.push(cur_node->left);
                if(cur_node->right) layer.push(cur_node->right);
            }
            count++;
        }
        return count;
    }
};


int main(){
    std::cout << "A tree represented by a space separated list (null for a missing node): ";
    std::string line;
    std::getline(std::cin, line);

    TreeNode_p root = string2tree(line);
    std::cout << "Minimum depth (by DFS): " << Solution().minDepth_DFS(root) << std::endl;
    std::cout << "Minimum depth (by BFS): " << Solution().minDepth_BFS(root) << std::endl;

    return 0;
}