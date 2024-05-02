#include<iostream>
#include<queue>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;
 
queue<int> interleave(queue<int>&q1,queue<int>&q2){

    int n = q1.size();

    int k = n;

    while(k--){
        q1.push(q1.front());
        q1.push(q2.front());

        q1.pop();
        q2.pop();
    }

    return q1;
}
int main()
{

    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);
    q1.push(40);

    queue<int> q2;
    q2.push(1);
    q2.push(2);
    q2.push(3);
    q2.push(4);

    q1 = interleave(q1,q2);

    while(!q1.empty()){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    cout<<endl;

return 0;
}