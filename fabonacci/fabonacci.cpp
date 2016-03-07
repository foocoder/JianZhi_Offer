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
        int Fibonacci(int n) {
            if(n==0 || n==1)
                return n;
            else
                return (Fibonacci(n-1)+Fibonacci(n-2));
        }

};

int main(int argc, char *argv[])
{
    Solution test;
    for(int i=0; i<100; i++)
        cout<<test.Fibonacci(i)<<endl;
    return 0;
}
