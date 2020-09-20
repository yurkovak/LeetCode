#include <memory>
#include <queue>

#include "parse_input.h"


void checkNode(const TreeNode* cur_node, const std::string& n_val){
    if (!cur_node) throw std::runtime_error("The provided list is incorrect, no parent node for " + n_val);
}


std::shared_ptr<TreeNode> string2tree(const std::string& line){
    std::istringstream ss(line);
    std::string n_val;

    // create root
    ss >> n_val;
    std::shared_ptr<TreeNode> root(nullptr);
    if (!n_val.empty() && n_val != "null"){
        root = std::make_shared<TreeNode>(TreeNode(std::stoi(n_val)));
    }
    else return root;

    // fill in level by level in order: left -> right, left -> right
    std::queue<std::shared_ptr<TreeNode>> level;
    level.push(root);
    bool left = true;
    std::shared_ptr<TreeNode> cur_node(nullptr);
    while (ss.rdbuf()->in_avail()){
        if (left){
            if (!level.empty()) {
                cur_node = level.front();
                level.pop();
            }
            else cur_node = nullptr;
        }
            
        ss >> n_val;
        if (n_val != "null") {
            checkNode(cur_node.get(), n_val);
            std::shared_ptr<TreeNode> new_node(new TreeNode(std::stoi(n_val)));
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


