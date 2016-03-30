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
    /*
        1、复制每个节点，如：复制节点A得到A1，将A1插入节点A后面
        2、遍历链表，A1->random = A->random->next;
        3、将链表拆分成原链表和复制后的链表
    */
    RandomListNode* Clone1(RandomListNode* pHead)// Copy and Split
    {
        if(!pHead) return NULL;
        RandomListNode *currNode = pHead;
        while(currNode){
            RandomListNode *node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }
        currNode = pHead;
        while(currNode){
            RandomListNode *node = currNode->next;
            if(currNode->random){
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }
        //拆分
        RandomListNode *pCloneHead = pHead->next;
        RandomListNode *tmp;
        currNode = pHead;
        while(currNode->next){
            tmp = currNode->next;
            currNode->next =tmp->next;
            currNode = tmp;
        }
        return pCloneHead;
    }
};

int main(int argc, char *argv[])
{

    return 0;
}
