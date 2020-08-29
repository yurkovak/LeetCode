#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };



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


void checkNode(const TreeNode* cur_node, const std::string& n_val){
    if (!cur_node) throw std::runtime_error("The provided list is incorrect, no parent node for " + n_val);
}


TreeNode* string2tree(const std::string &line){
    std::istringstream ss(line);
    std::string n_val;

    // create root
    ss >> n_val;
    TreeNode* root;
    if (!n_val.empty() && n_val != "null"){
        root = new TreeNode(std::stoi(n_val));
    }
    else return nullptr;

    // read the new level in order: for all current layer nodes fill left & right, left & right
    std::queue<TreeNode*> level;
    level.push(root);
    while (ss.rdbuf()->in_avail()){
        int new_level_size = level.size();
        for (int i = 0; i < new_level_size; i++){
            TreeNode* cur_node = level.front();
            level.pop();
            
            ss >> n_val;
            if (n_val != "null") {
                checkNode(cur_node, n_val);
                TreeNode* new_node = new TreeNode(std::stoi(n_val));
                cur_node->left = new_node;
                level.push(new_node);
            }
            else level.push(nullptr);

            ss >> n_val;
            if (n_val != "null") {
                checkNode(cur_node, n_val);
                TreeNode* new_node = new TreeNode(std::stoi(n_val));
                cur_node->right = new_node;
                level.push(new_node);
            }
            else level.push(nullptr);
        }
    }
    return root;
}


int main(){
    std::cout << "A tree represented by a space separated list (null for a missing node): ";
    std::string line; 
    std::getline(std::cin, line);

    TreeNode* root = string2tree(line);
    std::cout << "Maximum depth (by DFS): " << Solution().maxDepth_DFS(root) << std::endl;
    std::cout << "Maximum depth (by BFS): " << Solution().maxDepth_BFS(root) << std::endl;
}