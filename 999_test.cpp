#include<iostream>
#include<vector>
#include<deque>
//#include<bits/stdc++.h>
using namespace std;

vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int> dq;
        vector<int> ans;
        
        for(int i = 0;i<n;i++){
            
            // deque khali
            if(dq.empty()){
                dq.push_front(i);
            }
            else{
                //out of scope
                while(!dq.empty() && i-dq.front()>=k){
                    dq.pop_front();
                }
                
                while(!dq.empty() && arr[dq.back()]<=arr[i]){
                    dq.pop_back();
                }
                
                dq.push_back(i);
            }

            ans.push_back(arr[dq.front()]);
            
        }
        
        return ans;
    }
int main()
{

    int N = 9, K = 3;
    int arr[9] = {1,2,3, 1, 4, 5, 2, 3, 6};

    vector<int> a = max_of_subarrays(arr,N,K);

    for(int x=0;x<a.size();x++){
        cout<<a[x]<<" ";
    }
    return 0;
}