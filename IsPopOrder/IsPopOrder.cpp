// ---- Program Info Start----
//FileName:     IsPopOrder.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-13 15:52:45
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>
#include <stack>
#include <algorithm>

using namespace std;

class Solution{
    public:
        bool IsPopOrder(vector<int> &pushV,vector<int>&popV){
            if(pushV.empty() || popV.empty()) return false;
            int lenOfPush = pushV.size();
            if(lenOfPush != popV.size()) return false;

            vector<int> freeZone;
            stack<int> freezeZone;

            //Initialize free Zone;
            freeZone.reserve(lenOfPush);
            vector<int>::reverse_iterator rIt = pushV.rbegin();
            for(rIt; rIt != pushV.rend(); rIt++) {
                freeZone.push_back(*rIt);
            }

            for(auto i:popV){
                //Try to Find i in freeZone
                vector<int>::iterator it = find(freeZone.begin(), freeZone.end(), i);
                if(it != freeZone.end()) {
                    vector<int>::iterator pIt = freeZone.end();
                    while(--pIt != it){
                        freezeZone.push(*pIt);
                        freeZone.pop_back();
                    }
                    freeZone.pop_back();
                }
                else if(!freezeZone.empty())
                //Cant find i in freeZone; Try find i in freezeZone;
                {
                    if(i != freezeZone.top()) return false;
                    freezeZone.pop();
                }
                else
                    return false;
            }
            return true;
        }

        bool IsPopOrder(vector<int> pushV,vector<int> popV) {//Nowcoder version
            if(pushV.size() == 0) return false;
            vector<int> stack;
            for(int i = 0,j = 0 ;i < pushV.size();){
                stack.push_back(pushV[i++]);
                while(j < popV.size() && stack.back() == popV[j]){
                    stack.pop_back();
                    j++;
                }
            }
            return stack.empty();
        }
};

int main(int argc, char *argv[])
{
    ifstream infile("Test",ios::in);
    if(!infile){
        cerr<<"Cant Open Input File"<<endl;
        return -1;
    }
    string line;
    vector<vector<int> > vecTest;
    while(getline(infile, line)){
        istringstream streamline(line);
        int number;
        vector<int> vec;
        while(streamline>>number){
            vec.push_back(number);
        }
        streamline.clear();
        vecTest.push_back(vec);
    }
    infile.close();

    Solution test;
    int lenOfTest = vecTest.size();
    for(int i=0; i<lenOfTest; i+=2){
        for(auto j : vecTest[i]){
            cout<<j<<",";
        }
        cout<<"\b&&";
        for(auto j : vecTest[i+1]){
            cout<<j<<",";
        }
        cout<<"\b:";
        cout<<test.IsPopOrder(vecTest[i], vecTest[i+1])<<endl;
    }
    return 0;
}
