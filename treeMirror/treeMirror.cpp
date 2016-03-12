// ---- Program Info Start----
//FileName:     treeMirror.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-12 22:05:04
// ---- Program Info End  ----

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
        }
};
class Solution {
    public:
        void Mirror(TreeNode *pRoot) {//Non-Recursive Version
            if(pRoot == NULL) return;
            stack<TreeNode *> nodeStack;
            TreeNode * pNode = pRoot;
            while(pNode != NULL || !nodeStack.empty()){
                while(pNode != NULL){
                    nodeStack.push(pNode);
                    pNode = pNode->left;
                }
                if(!nodeStack.empty()){
                    pNode = nodeStack.top();
                    nodeStack.pop();
                    TreeNode * pTmp = pNode->left;
                    pNode->left = pNode->right;
                    pNode->right = pTmp;
                    pNode = pNode->left;
                }
            }
        }

        struct TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> in) {
            vector<int> leftPre, leftIn, rightPre, rightIn;
            struct TreeNode * rootNode = new struct TreeNode(pre[0]);
            //cout<<pre[0]<<" "; //Pre-Order Print;
            if(pre.size() == 1) return rootNode;
            int rootInPos;
            for(int i=0, len=in.size(); i<len; i++){
                if(in[i] == pre[0]) {
                    rootInPos = i;
                    break;
                }
            }
            if(rootInPos > 0)
            {
                leftPre.assign(pre.begin()+1, pre.begin()+rootInPos+1);
                leftIn.assign(in.begin(), in.begin()+rootInPos);
            }
            if(rootInPos < in.size())
            {
                rightPre.assign(pre.begin()+rootInPos+1, pre.end());
                rightIn.assign(in.begin()+rootInPos+1, in.end());
            }
            if(leftIn.size() > 0)
            {
                rootNode -> left = reConstructBinaryTree(leftPre, leftIn);
            }
            if(rightIn.size() > 0)
            {
                rootNode -> right = reConstructBinaryTree(rightPre, rightIn);
            }
            return rootNode;
        }

        void deleteBinaryTree(struct TreeNode * rootNode){
            if(rootNode->left != NULL){
                deleteBinaryTree(rootNode->left);
            }
            if(rootNode->right != NULL){
                deleteBinaryTree(rootNode->right);
            }
            cout<<rootNode->val<<" ";//Post-Order Print;
            delete rootNode;
            rootNode =NULL;
        }

};

int main(int argc, char *argv[])
{
    vector<int> pre0,in0;
    pre0.push_back(1);
    pre0.push_back(2);
    pre0.push_back(4);
    pre0.push_back(7);
    pre0.push_back(3);
    pre0.push_back(5);
    pre0.push_back(6);
    pre0.push_back(8);

    in0.push_back(4);
    in0.push_back(7);
    in0.push_back(2);
    in0.push_back(1);
    in0.push_back(5);
    in0.push_back(3);
    in0.push_back(8);
    in0.push_back(6);

    Solution test;
    struct TreeNode * rootNode1 = test.reConstructBinaryTree(pre0, in0);
    test.Mirror(rootNode1);
    test.deleteBinaryTree(rootNode1);
    return 0;
}
