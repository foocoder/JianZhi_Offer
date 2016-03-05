// ---- Program Info Start----
//FileName:     printListFromTailToHead.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-05 18:06:12
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
          val(x), next(NULL) {
    }
};

class Solution{
public:
    vector<int> printListFromTailToHead1(struct ListNode* head) {//Using Stack
        vector<int> varVec;
        stack<int> varStack;
        struct ListNode * ptrNode = head;
        while(ptrNode != NULL){
            varStack.push(ptrNode->val);
            ptrNode = ptrNode->next;
        }
        while(!varStack.empty()){
            varVec.push_back(varStack.top());
            varStack.pop();
        }
        return varVec;
    }

    vector<int> printListFromTailToHead2(struct ListNode* head) {//Using Insert of Vector
        vector<int> varVec;
        struct ListNode * ptrNode = head;
        while(ptrNode != NULL){
            varVec.insert(varVec.begin(), ptrNode->val);
            ptrNode = ptrNode->next;
        }
        return varVec;
    }

    void printListFromTailToHead0(struct ListNode* head) {//Using Recursive
        struct ListNode * ptrNode = head;
        if(ptrNode != NULL){
            if(ptrNode->next != NULL)
                printListFromTailToHead0(ptrNode->next);
            cout<<ptrNode->val<<" ";
        }
    }
};
int main(int argc, char *argv[])
{
    struct ListNode * head = new struct ListNode(0);
    struct ListNode * ptr  = head;
    for(int i=0; i<10; i++){
        struct ListNode * node = new struct ListNode(i+1);
        ptr->next = node;
        ptr = node;
    }
    ptr = head;
    while(ptr != NULL){
        cout<<ptr->val<<" ";
        ptr = ptr->next;
    }
    cout<<endl;
    Solution test;
    test.printListFromTailToHead0(head);
    //vector<int> varVec = test.printListFromTailToHead(head);
    //for(auto i : varVec)
        //cout<<i<<" ";

    //Deallocate Memory
    ptr = head;
    struct ListNode * ptrNext;
    while(ptr !=NULL){
        ptrNext = ptr->next;
        delete ptr;
        ptr = ptrNext;
    }
    return 0;
}
