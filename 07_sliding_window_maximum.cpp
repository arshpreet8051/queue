#include<iostream>
#include<vector>
#include<queue>
//#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        // store only large elements in deque -> u'll get decreasing order
        // remove samller and out of bounds elements
        // the front of the deque will yield the answer

        vector<int> ans;
        deque<int> dq;
        //Note : store indexs in Deque not elements

        for(int i = 0;i<nums.size();i++){

            // if dq if empty
            if(dq.empty()){
                dq.push_front(i);
            }
            else{

                // remove out of bounds elemets
                while(!dq.empty() && i-dq.front() >= k){
                    dq.pop_front();
                }

                // remove smaller elements coz they make no-sense
                while(!dq.empty() && nums[dq.back()] <= nums[i]){
                    dq.pop_back();
                }

                // add current ele index
                dq.push_back(i);
            }

            // note : we will only store ans if it corresponads to window od size k

            if(i>=k-1)ans.push_back(nums[dq.front()]);

        }

        return ans;
    }
};