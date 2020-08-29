#include <queue>
#include "parse_input.h"


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


