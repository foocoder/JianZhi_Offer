// ---- Program Info Start----
//FileName:     constructQueueBy2Stack.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-06 21:54:04
// ---- Program Info End  ----

#include <iostream>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>

using namespace std;

class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop1() {//My solution, a little complex
        int popNum;
        if(stack1.size()==0) return -1;
        while(stack1.size()>1){
            stack2.push(stack1.top());
            stack1.pop();
        }
        popNum = stack1.top();
        stack1.pop();
        while(stack2.size()>0){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return popNum;
    }

    int pop() {//Book version; Low complexity
        int popNum;
        if(stack2.empty()) {
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if(stack2.empty()) return -1;
        popNum = stack2.top();
        stack2.pop();
        return popNum;
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

class Solution1{//construct stack by 2 queue
public:
    void push(int node){
        if(!queue1.empty()){
            queue1.push(node);
        }
        else{
            queue2.push(node);
        }
    }

    int pop(){
        int popNum;
        queue<int> * masterQueue;
        queue<int> * secondQueue;
        if(!queue1.empty()){
            masterQueue = & queue1;
            secondQueue = & queue2;
        }
        else if(!queue2.empty()){
            masterQueue = & queue2;
            secondQueue = & queue1;
        }
        else if(queue1.empty() && queue2.empty()){
            return -1;
        }
        while(masterQueue->size()>1){
            secondQueue->push(masterQueue->front());
            masterQueue->pop();
        }
        popNum = masterQueue->front();
        masterQueue->pop();
        return popNum;
    }

private:
    queue<int> queue1;
    queue<int> queue2;
};

int main(int argc, char *argv[])
{
    Solution1 test;
    string line;
    while(getline(cin, line)){
        istringstream lineStream(line);
        int num;
        while(lineStream>>num)
            test.push(num);
    }
    int popNum;
    while((popNum=test.pop())!=-1)
        cout<<popNum<<" ";
    return 0;
}
