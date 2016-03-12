// ---- Program Info Start----
//FileName:     printMatrixClockwise.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-12 22:40:54
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> printMatrix(const vector<vector<int> > &matrix) {
        vector<int> result;
        int row = matrix.size();
        if(!row) return result;
        int column = matrix[0].size();
        if(!column) return result;

        int leftUp = 0, leftDown = 0, rightUp = column-1, rightDown = row-1;
        int i,j;
        while(leftUp <= rightDown && leftDown <= rightUp){
            for(i=leftUp,j=leftDown; j<=rightUp; j++){
                result.push_back(matrix[i][j]);
                //cout<<matrix[i][j]<<endl;
            }
            leftUp++;
            for(i=leftUp,j=rightUp; i<=rightDown; i++){
                result.push_back(matrix[i][j]);
                //cout<<matrix[i][j]<<endl;
            }
            rightUp--;
            for(j=rightUp,i=rightDown; j>=leftDown; j--){
                result.push_back(matrix[i][j]);
                //cout<<matrix[i][j]<<endl;
            }
            rightDown--;
            for(i=rightDown,j=leftDown; i>=leftUp; i--){
                result.push_back(matrix[i][j]);
                //cout<<matrix[i][j]<<endl;
            }
            leftDown++;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    ifstream infile("Test", ios::in);
    if(!infile){
        cerr<<"Wrong Input File"<<endl;
        return -1;
    }
    string line;
    vector<vector<int> >matrix;
    while(getline(infile,line)){
        istringstream streamline(line);
        int number;
        vector<int> array;
        while(streamline>>number){
            array.push_back(number);
        }
        matrix.push_back(array);
    }

    Solution test;
    vector<int> result = test.printMatrix(matrix);
    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}


