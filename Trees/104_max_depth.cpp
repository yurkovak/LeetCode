#include <algorithm>
#include <iostream>
#include <string>
#include <queue>

#include "parse_input.h"


class Solution {
public:
    // DFS: O(N) time, O(logN) space
    int maxDepth_DFS(const TreeNode* root) {
        if (!root)
            return 0;
    
        return 1 + std::max(maxDepth_DFS(root->left), maxDepth_DFS(root->right));
    }

    // BFS: O(N) time, O(N) space
    int maxDepth_BFS(const TreeNode* root) {        
        std::queue<const TreeNode*> layer;
        if (root) layer.push(root);
        
        int count = 0;
        while(!layer.empty()){
            int layer_size = layer.size();
            for (int i = 0; i < layer_size; i++){
                const TreeNode* cur_node = layer.front();
                layer.pop(); 
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

    TreeNode* root = string2tree(line);
    std::cout << "Maximum depth (by DFS): " << Solution().maxDepth_DFS(root) << std::endl;
    std::cout << "Maximum depth (by BFS): " << Solution().maxDepth_BFS(root) << std::endl;

    return 0;
}