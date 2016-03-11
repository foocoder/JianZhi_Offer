// ---- Program Info Start----
//FileName:     ReverseList.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-11 12:21:23
// ---- Program Info End  ----

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode * next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution{
    public:
        ListNode * ReverseList(ListNode * pListHead){
            if(pListHead == NULL) return pListHead;
            ListNode * pBefore = NULL;
            ListNode * p = pListHead;
            ListNode * pAfter = p->next;

            while(p -> next != NULL){
                p->next = pBefore;
                pBefore = p;
                p = pAfter;
                pAfter = p->next;
            }
            p ->next = pBefore;
            return p;
        }
};

int main(int argc, char *argv[])
{
    ListNode * pListHead = new ListNode(0);
    ListNode * p = pListHead;

    for(int i=1; i<10; i++){
        ListNode * p0 = new ListNode(i);
        p->next = p0;
        p = p0;
    }

    Solution test;
    p = test.ReverseList(pListHead);
    while(p!=NULL)
    {
        ListNode * tmp = p;
        cout<<p->val<<" ";
        p = p->next;
        delete tmp;
    }
    return 0;
}
