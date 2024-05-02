#include<vector>
#include<deque>
using namespace std;

#define and &&

vector<int> get_maxi(vector<int> &nums, int n, int k){
  vector<int> ans;
  deque<int> dq;

  // processing first k-sized window
  for(int i = 0;i<k;i++){

    // remove smaller elements
    while(!dq.empty() and nums[i]>=nums[dq.back()]){
      dq.pop_back();
    }

    dq.push_back(i);
  }

  ans.push_back(nums[dq.front()]);

  for(int i = k;i<n;i++){
    
    if(!dq.empty() and i-dq.front()>=k){
      dq.pop_front();
    }

    while(!dq.empty() and nums[i]>=nums[dq.back()]){
      dq.pop_back();
    }

    dq.push_back(i);

    ans.push_back(nums[dq.front()]);

  }

  return ans;
}

vector<int> get_mini(vector<int> &nums, int n, int k){

  vector<int> ans;
  deque<int> dq;

  // process first k sized window
  for(int i = 0;i<k;i++){
    // remove larger ele
    while(!dq.empty() and nums[i]<=nums[dq.back()]){
      dq.pop_back();
    }

    dq.push_back(i);
  }

  ans.push_back(nums[dq.front()]);

  // processing another windows
  for(int i = k;i<n;i++){

    // remove out of window ele
    if(!dq.empty() and i-dq.front()>=k){
      dq.pop_front();
    }

    while(!dq.empty() and nums[i]<=nums[dq.back()]){
      dq.pop_back();
    }

    dq.push_back(i);

    ans.push_back(nums[dq.front()]);

  }

  return ans;
}

long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	// Write your code here.
  long long ans = 0;

  // getting maximum from each subarray
  vector<int> maxi = get_maxi(nums,n,k);

  // getting minimum from each subarray
  vector<int> mini = get_mini(nums,n,k);


  // now return the answer after adding
  for(int i = 0;i<maxi.size();i++){
    ans += mini[i] + maxi[i];
  }

  return ans;
}
