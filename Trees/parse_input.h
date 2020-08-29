#ifndef PARSE_INPUT_H    
#define PARSE_INPUT_H

#include <string>
#include <sstream>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


void checkNode(const TreeNode* cur_node, const std::string& n_val);


TreeNode* string2tree(const std::string &line);


#endif