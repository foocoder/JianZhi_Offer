// ---- Program Info Start----
//FileName:     jumpFloor.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-08 22:19:20
// ---- Program Info End  ----

#include <iostream>

using namespace std;

class Solution {
public:
    //假设青蛙第一次跳一个，则剩下的为F(n-1)
    //假设青蛙第一次跳两个，则剩下的为F(n-2)
    //F(n) = F(n-1) + F(n-2);
    int jumpFloor(int number) {
        if(number==0 || number==1|| number==2)
            return number;
        int lastNum = 2, lastOfLast = 1;
        int currentNum;
        for(int i=3; i<=number; i++){
            currentNum = lastNum + lastOfLast;
            lastOfLast = lastNum;
            lastNum    = currentNum;
        }
        return currentNum;
    }
};

int main(int argc, char *argv[])
{
    Solution test;
    return 0;
}
