// ---- Program Info Start----
//FileName:     LinkedList.h
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-14 15:03:53
// ---- Program Info End  ----

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <vector>
#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x):val(x),next(NULL){
    }
};

class ListClass{
    //The Head Node is -1;
    ListNode * pListHead;
    public:
    //Constructor
    ListClass():pListHead(new ListNode(-1)){
        #ifdef DEBUG
        std::cout<<"Default"<<std::endl;
        #endif
    }
    ListClass(const std::vector<int> &vec):pListHead(new ListNode(-1)){
        if(vec.empty()) return;
        ListNode * p = pListHead;
        for(auto i:vec){
            ListNode * pTmp = new ListNode(i);
            p->next = pTmp;
            p = pTmp;
        }
        #ifdef DEBUG
        std::cout<<"Parameter"<<std::endl;
        #endif
    }

    //Copy Constructor
    ListClass(const ListClass & rhs):pListHead(rhs.pListHead){
        #ifdef DEBUG
        std::cout<< "Copy"<<std::endl;
        #endif
    }

    //Assign Function
    ListClass & operator=(const ListClass & rhs){
        //Check self Assignment
        if(&rhs == this){
            return *this;
        }

        //First Destruct All of Data in self object;
        //Or Memory Leak will Occur!
        while(pListHead != NULL){
            ListNode * pTmp = pListHead;
            pListHead = pListHead->next;
            delete pTmp;
        }
        //Copy Data From rhs to this;
        //Deep Copy
        pListHead = new ListNode(-1);
        ListNode * pThis = pListHead;
        ListNode * pRHS = rhs.pListHead->next;
        while(pRHS != NULL){
            ListNode * pTmp = new ListNode(pRHS->val);
            pThis->next = pTmp;
            pThis = pTmp;
            pRHS  = pRHS->next;
        }
        #ifdef DEBUG
        std::cout<<"Assignment"<<std::endl;
        #endif

        return *this;
    }

    //Destructor
    ~ListClass(){
        while(pListHead != NULL){
            ListNode * pTmp = pListHead;
            pListHead = pListHead->next;
            delete pTmp;
        }
        //Avoid Wild Pointer;
        pListHead = NULL;
        #ifdef DEBUG
        std::cout<<"Destructor"<<std::endl;
        #endif
    }

    //Get List Head
    ListNode * getListHead(){
        return pListHead->next;
    }

    //Print List Val
    void printList(){
        ListNode * p = pListHead->next;
        std::cout<<"\n---PrintLinkedListStart---"<<std::endl;
        if(p != NULL) {
            while(p != NULL){
                std::cout<<"("<<p->val<<")->";
                p = p->next;
            }
            std::cout<<"(NULL)";
        }else
            std::cout<<"List is NULL";
        std::cout<<"\n--- PrintLinkedListEnd ---"<<std::endl;
    }
};
#endif
