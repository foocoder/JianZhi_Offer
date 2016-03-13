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

class Solution{
    public:
        void push(int value){
            intStack.push(value);
        }

        void pop(){
            intStack.pop();
        }

        int top(){
            return intStack.top();
        }

        int min(){
            stack<int> tmp;
            if(intStack.empty()) return -2016;

            int minNumber = 0x7FFFFFFF;
            while(!intStack.empty()){
                int top = intStack.top();
                minNumber = top < minNumber ? top : minNumber;
                tmp.push(top);
                intStack.pop();
            }

            while(!tmp.empty()){
                intStack.push(tmp.top());
                tmp.pop();
            }
            return minNumber;
        }
    private:
        stack<int> intStack;

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
