// ---- Program Info Start----
//FileName:     BinaryTree.h
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-14 19:50:05
// ---- Program Info End  ----

#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BinaryTreeClass{
    TreeNode * root;
    public:
        //Constructor
        BinaryTreeClass();
        //Copy Constructor
        BinaryTreeClass(const BinaryTreeClass & rhs);
        //Assign Operator
        BinaryTreeClass & operator=(const BinaryTreeClass & rhs);
        //Destructor
        ~BinaryTreeClass();

        //Private Interface: Recursive Copy
        void RecursiveCopyNode(TreeNode * lhs, TreeNode * rhs);
        //Private Interface: Recursive Delete
        void RecursiveDeleteNode(TreeNode * rhs);

};

#endif
