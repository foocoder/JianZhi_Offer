// ---- Program Info Start----
//FileName:     PrintTreeFromTopToBottom.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-13 20:09:27
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
    public:
        vector<int> PrintFromTopToBottom(TreeNode *root) {
            vector<int> vecResult;
            if(root == NULL) return vecResult;
            deque<TreeNode *> nodeQueue;
            TreeNode * p = root;
            nodeQueue.push_back(p);
            while(!nodeQueue.empty()){
                p = nodeQueue.front();
                nodeQueue.pop_front();
                if(p!=NULL) {
                    vecResult.push_back(p->val);
                    nodeQueue.push_back(p->left);
                    nodeQueue.push_back(p->right);
                }
            }
            return vecResult;
        }
};

