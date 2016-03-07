// ---- Program Info Start----
//FileName:     minNumberInRotateArr.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-07 17:13:01
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {//Wrong Version
        int sizeOfArr = rotateArray.size();
        if(!sizeOfArr) return NULL;
        int partition = rotateArray[sizeOfArr-1];
        int low = 0, high = sizeOfArr - 1;
        int current = (low+high)/2;
        if(rotateArray[low] < rotateArray [high]) return rotateArray[low];
        while(low < high){
            if(rotateArray.at(low) == rotateArray.at(current) && rotateArray.at(high) == rotateArray.at(current)){
                while(low<=high){
                    if(rotateArray.at(low++)<partition)
                        partition = rotateArray.at(low-1);
                }
                return partition;
            }
            else if(rotateArray.at(current) > partition){//current at the first seq
                low = current+1;
            }
            else{
                high = current;
                partition = rotateArray.at(current);
            }
            current = (low + high) / 2;
        }
        return partition;
    }
};

int main(int argc, char *argv[])
{
    Solution test;
    ifstream infile("Test", ios::in);
    string line;
    if(!infile){
        cerr<<"Open Test Sample Failed"<<endl;
        return -1;
    }
    while(getline(infile, line)){
        istringstream lineStream(line);
        int number;
        vector<int> rotateArray;
        while(lineStream>>number){
            rotateArray.push_back(number);
        }
        cout<<test.minNumberInRotateArray(rotateArray)<<endl;
    }
    return 0;
}
