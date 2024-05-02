#include<iostream>
#include<vector>
#include<queue>
#include<stack>
//#include<bits/stdc++.h>
using namespace std;
 
void reverse_first_k(queue<int>&q,int k){

    // step 1: reverse k using stack
    stack<int> st;

    if(k==0 || k>q.size()){return;}

    int x = k;
    while(x--){
        st.push(q.front());
        q.pop();
    }

    // step 2: now push back elements in queue
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }

    // step 3: pop n-k ele and push back again in queue
    int z = q.size()-k;
    while(z--){
        q.push(q.front());
        q.pop();
    }
}
int main()
{   
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5)
    ;
    reverse_first_k(q,5);


    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;

    return 0;
}