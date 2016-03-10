// ---- Program Info Start----
//FileName:     reOrderArray.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-10 15:37:44
// ---- Program Info End  ----

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

class Solution{
    public:
        void reOrderArr0( vector<int> &arr ){//The Simplest Solution, Using O(n) extra Space, O(n) complexity
            vector<int> odd;
            vector<int> even;
            for(auto i : arr)
                if(i&1)
                    odd.push_back(i);
                else
                    even.push_back(i);
            arr.clear();
            for(auto i : odd)
                arr.push_back(i);
            for(auto i : even)
                arr.push_back(i);
        }
        void reOrderArr( vector<int> & arr ){//Like bubble sort, O(n2) complexity
            int changable = 0;
            for (int i = 0; i < arr.size();i++)
            {
                for (int j = arr.size() - 1; j>i;j--)
                {
                    if (arr[j] % 2 == 1 && arr[j - 1]%2 == 0) //前偶后奇交换
                    {
                        swap(arr[j], arr[j-1]);
                        changable += 2;
                    }
                }
            }
            cout<<"Bubble sort "<<changable;
        }

        void reOrderArr2( vector<int> &a ) {
            int i = 0,j;
            int changable=0;
            int lenA = a.size();
            while(i<lenA){
                while(i<lenA&&(a[i]&1))
                    i++;
                j = i+1;
                while(j<lenA&&!(a[j]&1))
                    j++;
                if(j<lenA){
                    int tmp = a[j];
                    for (int j2 = j-1; j2 >=i; j2--) {
                        a[j2+1] = a[j2];
                        changable ++ ;
                    }
                    a[i++] = tmp;
                    changable ++ ;
                }else{// 查找失敗
                    break;
                }
            }
            cout<<"move "<<changable;
        }
        void swap(int & a, int & b){
            int tmp = a;
            a = b;
            b = tmp;
        }
};

int main(int argc, char *argv[])
{
    Solution test;
    string line;
    clock_t start, end;
    ifstream infile("Test",ios::in);
    if(!infile){
        cerr<<"Input File Test Cant Opened!"<<endl;
        return -1;
    }

    start = clock();
    while(getline(infile, line)){
        istringstream lineStream(line);
        int number;
        vector<int> arr;
        cout<<"\nInput: ";
        while(lineStream>>number){
            arr.push_back(number);
            cout<<number<<" ";
        }
        test.reOrderArr2(arr);
        cout<<"\nOutput: ";
        for(auto i : arr)
            cout<<i<<" ";
    }
    end = clock();
    cout<<"\n time "<<(end - start)<<endl;

    return 0;
}
