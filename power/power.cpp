// ---- Program Info Start----
//FileName:     power.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-09 22:13:19
// ---- Program Info End  ----

#include <iostream>
#include <ctime>

using namespace std;

class Solution {
public:
    double Power0(double base, int exponent) {//O(n) recursive version
        if(exponent == 0)
            return 1;
        else
            return exponent > 0 ? (base * Power0(base, exponent-1)) : ((double) 1)/(base * Power0(base, -exponent - 1));
    }

    double Power1(double base, int exponent){//O(n) Non- recursive version
        if(exponent == 0)
            return 1;
        else
        {
            int e = exponent > 0 ? exponent : -exponent;
            double result = base;
            for(int i=1; i<e; i++){
                result *= base;
            }
            return exponent > 0 ? result : ((double)1/result);
        }


    }

    double Power(double base, int exponent) {//O(log(n)) recursive version
        if(exponent == 0)
            return 1;
        else
        {
            double result;
            double half = exponent > 0 ? Power(base, exponent>>1) : Power(base, -exponent>>1);
            result = half*half;
            if(exponent & 1)
                result  *= base;
            return exponent > 0 ? result: ((double)1)/result;
        }
    }

    double Power2(double base, int exponent){//O(log(n)) Non- recursive version
        if(exponent == 0)
            return 1;
        else
        {
            int e = exponent > 0 ? exponent : -exponent;
            double result = base;
            while(e){
                result = base * base;
                if(e & 1)
                {
                    result *= base;
                }
                e >> 1;
            }
            return exponent > 0 ? result : ((double)1/result);
        }


    }
};

int main(int argc, char *argv[])
{
    Solution test;
    clock_t start, end;
    start = clock();
    //for(int i=0; i<10 ; i++){
        //cout<<i<<" 0 pow:"<<test.Power(i, 0)<<endl;
        //cout<<i<<" 1 pow:"<<test.Power(i, 1)<<endl;
        //cout<<i<<" 2 pow:"<<test.Power(i, 2)<<endl;
        //cout<<i<<" 3 pow:"<<test.Power(i, 3)<<endl;
    //}
    for(int i=-10; i<10; i++)
        cout<<test.Power0(2,i)<<",";
    end = clock();
    cout<<"\ntime:"<<(end-start)<<endl;

    start = clock();
    for(int i=-10; i<10; i++)
        cout<<test.Power(2,i)<<",";
    end = clock();
    cout<<"\ntime:"<<(end-start)<<endl;

    start = clock();
    for(int i=-10; i<10; i++)
        cout<<test.Power1(2,i)<<",";
    end = clock();
    cout<<"\ntime:"<<(end-start)<<endl;

    start = clock();
    for(int i=-10; i<10; i++)
        cout<<test.Power1(2,i)<<",";
    end = clock();
    cout<<"\ntime:"<<(end-start)<<endl;

    return 0;
}
