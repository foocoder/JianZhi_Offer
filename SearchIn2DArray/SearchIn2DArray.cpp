// ---- Program Info Start----
//FileName:     SearchIn2DArray.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-03 22:53:26
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution{
    public:
        bool Find1(vector<vector<int> > array, int target){
            for(auto i : array){
                for(auto j : i){
                    if(j == target){
                        return true;
                    }
                }
            }
            return false;
        }
        bool Find2(vector<vector<int> > array, int target){
            int as = array.size();
            int i = as;
            for(; i>=0; i--){
                if(array[i][i] == target){
                    return true;
                }
                else if(array[i][i] < target){
                    break;
                }
            }
            if(i<0 || i==as){
                return false;
            }else{
                for(int j=1; j<=as; j++){
                    //if(i+j<as){
                        //if(array[i][i+j])
                    //}
                    if(array[i+j<as?(i):(i+1)][i+j<as?(i+j):(i+j-as)] == target){
                        return true;
                    }
                    else return false;
                }

            }
            return false;
        }
};

int main(int argc, char *argv[])
{
    Solution test;
    vector<vector<int>> array;
    string line;
    int target;

    cout<<"array:";
    while(getline(cin,line)){
        vector<int> tmp;
        int number;
        istringstream stream(line);
        while(stream>>number){
            tmp.push_back(number);
        }
        if(!tmp.size()){
            break;
        }

        array.push_back(tmp);
    }
    cout<<"\ntarget:";
    cin>>target;

    if(test.Find2(array, target)){
        cout<<"\ntrue"<<endl;
    }else{
        cout<<"\nfalse"<<endl;
    }

    return 0;
}
