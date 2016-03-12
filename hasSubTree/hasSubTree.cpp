// ---- Program Info Start----
//FileName:     hasSubTree.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-12 20:04:26
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
    public:
        bool HasSubtree(TreeNode * pRoot1, TreeNode * pRoot2){
            if(pRoot1 == NULL && pRoot2 == NULL) return true;
            if(pRoot1 == NULL && pRoot2 != NULL) return false;
            if(pRoot1 != NULL && pRoot2 == NULL) return true;

            vector<int> preOrderSeq1 = PreOrderTraverse(pRoot1);
            vector<int> preOrderSeq2 = PreOrderTraverse(pRoot2);
            vector<int>::iterator it = search(preOrderSeq1.begin(), preOrderSeq1.end(), preOrderSeq2.begin(), preOrderSeq2.end());
            if(it!=preOrderSeq1.end())
                return true;
            else
                return false;
        }

        vector<int> PreOrderTraverse(TreeNode * pRoot){
            vector<int> preOrderSeq;
            if(pRoot == NULL) return preOrderSeq;
            stack<TreeNode *> nodeStack;
            TreeNode * pNode = pRoot;
            while(pNode != NULL || !nodeStack.empty()){
                while(pNode != NULL){
                    nodeStack.push(pNode);
                    preOrderSeq.push_back(pNode->val);
                    pNode = pNode->left;
                }
                if(!nodeStack.empty()){
                    pNode = nodeStack.top();
                    nodeStack.pop();
                    pNode = pNode->right;
                }
            }
            return preOrderSeq;
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
            //cout<<rootNode->val<<" ";//Post-Order Print;
            delete rootNode;
            rootNode =NULL;
        }
};

int main(int argc, char *argv[])
{

    vector<int> pre0,in0,pre1,in1;
    //pre0.push_back(1);
    //pre0.push_back(2);
    //pre0.push_back(4);
    //pre0.push_back(7);
    //pre0.push_back(3);
    //pre0.push_back(5);
    //pre0.push_back(6);
    pre0.push_back(8);

    //in0.push_back(4);
    //in0.push_back(7);
    //in0.push_back(2);
    //in0.push_back(1);
    //in0.push_back(5);
    //in0.push_back(3);
    in0.push_back(8);
    //in0.push_back(6);

    pre1.push_back(3);
    pre1.push_back(9);
    pre1.push_back(2);
    in1.push_back(9);
    in1.push_back(3);
    in1.push_back(2);

    Solution test;
    struct TreeNode * rootNode1 = test.reConstructBinaryTree(pre0, in0);
    struct TreeNode * rootNode2 = test.reConstructBinaryTree(pre1, in1);
    cout<<test.HasSubtree(rootNode1, rootNode2);
    test.deleteBinaryTree(rootNode1);
    test.deleteBinaryTree(rootNode2);
    return 0;
}
