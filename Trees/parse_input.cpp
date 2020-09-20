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

    // fill in level by level in order: left -> right, left -> right
    std::queue<TreeNode*> level;
    level.push(root);
    bool left = true;
    TreeNode* cur_node;
    while (ss.rdbuf()->in_avail()){
        if (left){
            if (level.size()) {
                cur_node = level.front();
                level.pop();
            }
            else cur_node = nullptr;
        }
            
        ss >> n_val;
        if (n_val != "null") {
            checkNode(cur_node, n_val);
            TreeNode* new_node = new TreeNode(std::stoi(n_val));
            if (left)
                cur_node->left = new_node;
            else
                cur_node->right = new_node;
            level.push(new_node);
        }

        left = !left;
    }
    return root;
}


