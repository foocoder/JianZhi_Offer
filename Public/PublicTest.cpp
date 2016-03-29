// ---- Program Info Start----
//FileName:     PublicTest.cpp
//
//Author:       Fuchen Duan
//
//Email:        slow295185031@gmail.com
//
//CreatedAt:    2016-03-14 16:33:09
// ---- Program Info End  ----

#include <iostream>
#include <vector>
#include "LinkedList.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Test LinkedList.h
    vector<int> vec0 = {1,2,3,4,5};
    vector<int> vec1 = {1};
    vector<int> vec2;

    cout<<"--Obj0---"<<endl;
    ListClass listNodeObj0 = ListClass(vec0);//Parameter Constructor
    cout<<"--Obj0---"<<endl;

    cout<<"--Obj1---"<<endl;
    ListClass listNodeObj1 ; // Default Constructor
    listNodeObj1 = vec1; //Assign Function Invoked
    cout<<"--Obj1---"<<endl;

    cout<<"--Obj2---"<<endl;
    ListClass listNodeObj2 = vec1; //Parameter Constructor
    cout<<"--Obj2---"<<endl;

    cout<<"--Obj3---"<<endl;
    ListClass listNodeObj3; // Default Constructor
    cout<<"--Obj3---"<<endl;

    cout<<"obj0:";
    listNodeObj0.printList();
    cout<<"obj1:";
    listNodeObj1.printList(); // listNodeObj1 Double Free
    cout<<"obj2:";
    listNodeObj2.printList();
    cout<<"obj3:";
    listNodeObj3.printList();
    return 0;
}
