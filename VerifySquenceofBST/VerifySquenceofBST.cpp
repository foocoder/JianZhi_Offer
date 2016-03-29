// ---- Program Info Start----
//FileName:     VerifySquenceofBST.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-29 16:45:21
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution{
    public:
        bool VerifySquenceofBST(const vector<int> &sequence){//Recursive Version
            if(sequence.empty()) return false;
            return Verify_Iter_of_BST(sequence.cbegin(), sequence.cend()-1);
        }
        bool Verify_Iter_of_BST(vector<int>::const_iterator first, vector<int>::const_iterator last){
            vector<int>::const_iterator iter;
            greater<int> gt;
            less<int> lt;
            bool flag = true;
            int root = *(last);
            iter = find_if(first, last, bind2nd(gt, root));
            if(iter != last){ // The Right subtree is not null
                vector<int>::const_iterator rIter = find_if(iter, last, bind2nd(lt, root));
                if(rIter != last){//Find it
                    return false;
                }
                //Recursion
                flag &= Verify_Iter_of_BST(iter, last-1);
            }
            if(iter != first){
                vector<int>::const_iterator lIter = find_if(first, iter, bind2nd(gt, root));
                if(lIter != iter){
                    return false;
                }
                //Recursion
                flag &= Verify_Iter_of_BST(first, iter-1);
            }
            return flag;

        }
};


int main(int argc, char *argv[])
{
    Solution test;
    vector<int> seq{2,6,3,7,6,10,9,12,13,11,8,5};
    cout<<test.VerifySquenceofBST(seq);
    return 0;
}
