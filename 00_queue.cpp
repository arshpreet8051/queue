#include<iostream>
//#include<bits/stdc++.h>
using namespace std;
 
class Queue{

    public:
    int size;
    int front;
    int rear;
    int *arr;

    Queue(int s){
        this->size = s;
        this->arr = new int[size];
        this->front = 0;
        this->rear = 0;
    }

    void push(int x){

        // check for overflow
        if(rear == size){
            cout<<"Queue overflow";
        }
        else{
            arr[rear] = x;
            rear++;
        }

    }

    int pop(){

        // check underflow

        if(front == rear){
            cout<<"Queue Underflow"<<endl;
            return -1;
        }
        else{
            int x = arr[front];
            arr[front] = -1;// just for safety
            front++;
            
            // for better memory management 👇🏼
            if(front == rear){
                front = 0;
                rear = 0;
            }
            return x;
        }
    }

    int get_size(){
        return (rear-front);
    }


    int get_front(){
        if(front==rear){return -1;}
        return arr[front];
    }
    

};
int main()
{
    Queue q = Queue(5);
    q.push(10);
    
    cout<<"front"<<q.get_front()<<endl;
    
    q.push(20);
    cout<<"size"<<q.get_size()<<endl;
    cout<<"front"<<q.get_front()<<endl;

    
    q.push(30);
    cout<<"size"<<q.get_size()<<endl;
    cout<<"front"<<q.get_front()<<endl;

    q.pop();
    cout<<"size"<<q.get_size()<<endl;
    cout<<"front"<<q.get_front()<<endl;
    return 0;
}