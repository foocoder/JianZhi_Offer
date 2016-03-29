// ---- Program Info Start----
//FileName:     FindPath.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-29 20:23:14
// ---- Program Info End  ----

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode{
    int val;
    struct TreeNode * left;
    struct TreeNode * right;
    TreeNode(int x):
        val(x), left(NULL), right(NULL){};
};
class Solution{
    public:
        vector<vector<int>> FindPath(TreeNode * root, int expectNumber){
            vector<int> vec;
            Find_Path(root, expectNumber, vec);
            return output;
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
    private:
        vector<vector<int>> output;
        void Find_Path(TreeNode * root, int expectNumber, vector<int> &vec){
            if(root == NULL) {
                vec.push_back(0);//占位符
                return;
            }
            vec.push_back(root->val);
            if(root->val <= expectNumber){
                if(root->val == expectNumber && !root->left && !root->right)
                    output.push_back(vec);
                else{
                    Find_Path(root->left, expectNumber-root->val, vec);
                    vec.pop_back();
                    Find_Path(root->right, expectNumber-root->val, vec);
                    vec.pop_back();
                }
            }
        }

};

int main(int argc, char *argv[])
{

    vector<int> pre,in;
    pre.push_back(1);
    pre.push_back(2);
    pre.push_back(4);
    pre.push_back(7);
    pre.push_back(3);
    pre.push_back(5);
    pre.push_back(6);
    pre.push_back(8);

    in.push_back(4);
    in.push_back(7);
    in.push_back(2);
    in.push_back(1);
    in.push_back(5);
    in.push_back(3);
    in.push_back(8);
    in.push_back(6);

    Solution test;
    struct TreeNode * rootNode = test.reConstructBinaryTree(pre, in);
    vector<vector<int>> result = test.FindPath(rootNode, 4);

    for(auto i:result)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<endl;
    }
    test.deleteBinaryTree(rootNode);
    return 0;
}
