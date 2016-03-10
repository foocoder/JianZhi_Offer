// ---- Program Info Start----
//FileName:     findKthToTail.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-10 21:57:52
// ---- Program Info End  ----

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) { }
};

class Solution {
    public:
        ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
            int len = 0, pos;
            ListNode * p = pListHead;
            while(p != NULL){
                p = p->next;
                len ++;
            }
            cout<<len<<endl;
            pos = len - k;
            if(pos < 0 || pos >= len)
                return NULL;
            p = pListHead;
            while(pos--){
                p = p->next;
            }
            return p;
        }
};


int main(int argc, char *argv[])
{
    ListNode * pListHead = new ListNode(0);
    ListNode * p = pListHead;
    for(int i=1; i<6; i++){
        ListNode * pListMem = new ListNode(i);
        p->next = pListMem;
        p = pListMem;
    }

    Solution test;
    for(int i=6; i<7; i++){
        p = test.FindKthToTail(pListHead, i);
        if(p!=NULL)
            cout<<p->val<<" ";
        else
            cout<<"NULL"<<" ";
    }
    return 0;
}
