#include<iostream>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;

string solve(string& s){

    string ans = "";
    int freq[26] = {0}; // to store frequency of char
    queue<char> q;      // to track valid candidates

    for(auto ch : s){

        // 1) increment frequency
        freq[ch-'a'] ++;

        // 2) push in queue
        q.push(ch);

        // 3) check for 1st non repeating in queue
        while(!q.empty()){

            if(freq[q.front()-'a'] > 1){
                q.pop(); // remove repeating chars
            }
            else{
                ans += q.front();
                break;
            }
        }

        if(q.empty()){
            ans+='#';
        }

    }

    return ans;
}

int main()
{   

    string sample = "aabc";

    string ans = solve(sample);

    for(auto ch:ans){
        cout<<ch<<" ";
    }

    return 0;
}