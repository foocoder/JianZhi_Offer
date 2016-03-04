// ---- Program Info Start----
//FileName:     ReplaceSpace.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-04 21:52:10
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution{
    public:
        void replaceSpace(char *str, int length){
            vector<char *> vecStr;
            char *replaceSpace = new char[3*length];
            char space[] = "%20";
            vecStr.clear();
            vecStr.push_back(str);
            for(int i=0; i<length; i++){
                if(str[i] == ' '){
                    vecStr.push_back(space);
                    str[i] = '\0';
                    if(i!=length-1)
                        vecStr.push_back(&str[i+1]);
                }
            }
            char * pointerToStr = replaceSpace;
            for(auto i : vecStr){
                //cout<<i;
                strcpy(pointerToStr, i);
                pointerToStr += strlen(i);
            }
            strcpy(str, replaceSpace);
        }
};

int main(int argc, char *argv[])
{
    Solution test;
    char * line = new char[100];
    cin.getline(line,100);
    test.replaceSpace(line, strlen(line));
    cout<<line<<endl;
    return 0;
}
