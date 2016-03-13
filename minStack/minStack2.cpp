// ---- Program Info Start----
//FileName:     minStack.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-13 14:01:45
// ---- Program Info End  ----

#include <iostream>
#include <stack>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class Solution{//O(1) Version
    public:
        void push(int value){
            valStack.push(value);
            minStack.empty()?minStack.push(value):minStack.push(value<minStack.top()?value:minStack.top());
        }

        void pop(){
            valStack.pop();
            minStack.pop();
        }

        int top(){
            return valStack.empty()?-1:valStack.top();
        }

        int min(){
            return minStack.empty()?-1:minStack.top();
        }
    private:
        stack<int> valStack;
        stack<int> minStack;

};

int main(int argc, char *argv[])
{
    ifstream infile("Test");
    if(!infile){
        cerr<< "Wrong Open Test"<<endl;
        return -1;
    }

    string line;
    while(getline(infile, line)){
        istringstream streamline(line);
        int number;
        Solution test;
        while(streamline>>number){
            test.push(number);
        }
        cout<<test.min()<<endl;
    }

    return 0;
}
