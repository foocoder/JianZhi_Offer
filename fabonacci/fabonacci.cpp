// ---- Program Info Start----
//FileName:     fabonacci.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-07 21:57:01
// ---- Program Info End  ----

#include <iostream>

using namespace std;
class Solution {
    public:
        int Fibonacci(int n) {// recursive version
            if(n==0 || n==1)
                return n;
            else
                return (Fibonacci(n-1)+Fibonacci(n-2));
        }

        int Fibonacci0(int n){// non-recursive version
            if(n==0 || n==1)
                return n;
            int lastNum = 1, lastOfLast = 0;
            int currentNum;
            for(int i=2; i<=n; i++){
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
    for(int i=0; i<50; i++)
        cout<<test.Fibonacci0(i)<<endl;
    return 0;
}
