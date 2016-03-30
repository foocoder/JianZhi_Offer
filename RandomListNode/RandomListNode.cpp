// ---- Program Info Start----
//FileName:     RandomListNode.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-30 10:53:18
// ---- Program Info End  ----

#include <iostream>
#include <map>

using namespace std;

struct RandomListNode{
    int label;
    struct RandomListNode * next, *random;
    RandomListNode(int x):
        label(x), next(NULL), random(NULL){};
};

class Solution{
    public:
        RandomListNode* Clone(RandomListNode* pHead){//Using Map Container
            if(!pHead) return pHead;
            map<int , RandomListNode *> listMap;

            //Process List Head
            RandomListNode * oldPtrHead = pHead;
            RandomListNode * newPtrHead = new RandomListNode(pHead->label);
            RandomListNode * ptrList = newPtrHead;
            listMap.insert(pair<int, RandomListNode*>(oldPtrHead->label, oldPtrHead));
            oldPtrHead = oldPtrHead->next;

            while(oldPtrHead){
                ptrList->next = new RandomListNode(oldPtrHead->label);
                listMap.insert(pair<int, RandomListNode*>(oldPtrHead->label, oldPtrHead));
                oldPtrHead = oldPtrHead->next;
                ptrList = ptrList->next;
            }

            ptrList = newPtrHead;
            oldPtrHead = pHead;
            while(oldPtrHead){
                //Considering When random pointer to NULL
                ptrList->random = oldPtrHead->random == NULL?NULL:listMap[oldPtrHead->random->label];
                ptrList = ptrList->next;
                oldPtrHead = oldPtrHead->next;
            }
            return newPtrHead;
        }

};

int main(int argc, char *argv[])
{

    return 0;
}
