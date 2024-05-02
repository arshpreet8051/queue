#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;


class MyQueue{

    // Requirements:
public:
    int* arr;
    int* next;
    int* front;
    int* rear;
    int freespot; 
    
    MyQueue(int size,int k){

        arr = new int[size];
        next = new int[size];

        front = new int[k];
        rear = new int[k];

        freespot = 0;

        // intializing arrays

        for(int i = 0;i<size;i++){
            next[i] = i+1;
        }
        next[size-1] = -1;

        for(int i = 0;i<k;i++){
            front[i] = rear[i] = -1;
        }
    }

    // pushing logic
    bool push(int x,int i){

        // step : 1 -> check overflow
        if(freespot == -1){return false;}

        // step : 2 -> find free index
        int index = freespot;

        // step : 3 -> update freespot
        freespot = next[index];

        // step : 4 -> check if inserting 1st element
        if(front[i] == -1){
            front[i] = index;
        }
        else{
            next[rear[i]] = index;
        }

        // step : 5 -> update rear
        rear[i] = index;

        // step : 6 -> update next
        next[index] = -1;

        // step : 7 -> push element
        arr[index] = x;
        return true;
    }


    // popping logic
    int pop(int i){

        // step : 1 -> check for underflow
        if(front[i] == -1){return -1;}

        // step : 2 -> find index to pop
        int index = front[i];

        // step : 3 -> update front
        front[i] = next[index];

        // step : 4 -> update next array 
        next[index] = freespot;

        // step : 5 -> update freespot
        freespot = index;

        return arr[index];
    }

    ~MyQueue(){
        delete[] arr;
        delete[] next;
        delete[] front;
        delete[] rear;
    }
};

int main()
{

    MyQueue q(8,3);
    cout<<q.push(1,0)<<endl;
    cout<<q.push(2,0)<<endl;
    cout<<q.push(5,1)<<endl;
    cout<<q.push(3,0)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(1)<<endl;
    cout<<q.pop(0)<<endl;
    cout<<q.pop(0)<<endl;
    cout<<q.pop(1)<<endl;

    return 0;
}