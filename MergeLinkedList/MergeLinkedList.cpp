// ---- Program Info Start----
//FileName:     MergeLinkedList.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-11 18:54:42
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
        ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
            if(pHead1==NULL) return pHead2;
            if(pHead2==NULL) return pHead1;
            ListNode *p1, *p2;
            if(pHead1->val > pHead2->val){
                ListNode * pTmp = pHead1;
                pHead1 = pHead2;
                pHead2 = pTmp;
            }
            p1 = pHead1;
            p2 = pHead2;
            for(;;){
                while(p1->next != NULL && p1->next->val < p2->val)
                {
                    p1 = p1->next;
                }
                if(p1->next == NULL){
                    p1->next = p2;
                    break;
                }
                ListNode * pTmp = p1->next;
                p1->next = p2;
                p2 = pTmp;
                p1 = p1->next;
            }
            return pHead1;
        }
};

int main(int argc, char *argv[])
{
    ListNode * pHead1 = new ListNode(0), * pHead2 = new ListNode(0), *p = pHead1;
    for(int i=1; i<10; i++)
    {
        ListNode * pTmp = new ListNode(2*i+1);
        p->next = pTmp;
        p = pTmp;
    }
    p = pHead2;
    for(int i=1; i<10; i++)
    {
        ListNode * pTmp = new ListNode(2*i);
        p->next = pTmp;
        p = pTmp;
    }
    Solution test;
    p = test.Merge(pHead1, pHead2);
    while(p!=NULL){
        cout<<p->val<<",";
        p = p->next;
    }

    //Free Memory
    return 0;
}
