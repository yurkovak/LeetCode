#ifndef PARSE_INPUT_H    
#define PARSE_INPUT_H

#include <memory>
#include <string>
#include <sstream>


struct TreeNode {
    int val;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


void checkNode(const TreeNode* cur_node, const std::string& n_val);


std::shared_ptr<TreeNode> string2tree(const std::string& line);


typedef std::shared_ptr<TreeNode> TreeNode_p;


#endif