// ---- Program Info Start----
//FileName:     BinaryTree.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-05-03 22:49:43
// ---- Program Info End  ----

#include "BinaryTree.h"

inline BinaryTreeClass::BinaryTreeClass():root(NULL){
}

BinaryTreeClass::BinaryTreeClass(const BinaryTreeClass &rhs){
    if(!rhs.root) {
        root = NULL;
        return;
    }
    root = new TreeNode(0);
    RecursiveCopyNode(root, rhs.root);
}

BinaryTreeClass & BinaryTreeClass::operator=(const BinaryTreeClass &rhs){

}

//Unchecked
void BinaryTreeClass::RecursiveCopyNode(TreeNode * lhs, TreeNode * rhs){
    lhs->val = rhs->val;
    if(!rhs->left) {
        lhs->left = new TreeNode(0);
        RecursiveCopyNode(lhs->left, rhs->left);
    }
    if(!rhs->right){
        lhs->right = new TreeNode(0);
        RecursiveCopyNode(lhs->right, rhs->right);
    }
}

//Unchecked
void BinaryTreeClass::RecursiveDeleteNode(TreeNode * rhs){
    if(!rhs->left){
        RecursiveDeleteNode(rhs->left);
        rhs->left = NULL;
    }
    if(!rhs->right){
        RecursiveDeleteNode(rhs->right);
        rhs->right = NULL;
    }
    //Delete Self
    delete rhs;
}
