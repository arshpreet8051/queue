#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;

class c_queue{

    public:
    int *arr;
    int front;
    int rear;
    int size;

    c_queue(int s){
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data){

        // check for overflow condition
        if((rear + 1)%size == front){
            cout<<"Queue overflow"<<endl;
            return;
        }
        // push element
        else{

            // if pushing 1st ele (special case)
            if(front == -1){front = rear = 0;}

            arr[(rear+1)%size] = data;
            rear++;
        }
    }

    int pop(){

        // check for underflow condition
        if( (front == -1 && rear == -1) || (front > rear)){

            if(front>rear){front = rear = -1;}
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        // pop and return ele
        int ele = arr[front];
        front++;
        return ele;
    }
};