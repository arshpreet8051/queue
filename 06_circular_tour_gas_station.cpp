#include<iostream>
#include<vector>
//#include<bits/stdc++.h>
using namespace std;

// approach -> 1 (optimized) ( T.C = O(n) )
int circular_tour(vector<int>&petrol,vector<int>&distance,int n){

    int ans = 0;    // right index to start 

    int balance = 0;   // kina extra petrol bachda
    int defecit = 0;   // kina petrol ghat reha


    for(int i = 0;i<n;i++){

        balance = (petrol[i] + balance) - distance[i];     // how much left after usage

        if(balance < 0){    // balance less than zero means ghat gya

            defecit = defecit + balance; // add defecit till now && new defecit (multiple defecit case)

            balance = 0; // for new start
 
            ans = i+1;  // je i tk circle complete nahe hoia ta i+1 to pehla koi nahi kar skda
        }
    }

    if(defecit + balance >= 0){return ans;}
    return -1;

}

// --------------------------------------------------------------------------------------------------------------------

// approach -> 2 same as approach 1 just little bit change

// in Python

// pehla check krlena v jan joga petrol haiga v a ke nahi

/*
    def circular_tour(petrol,distance,n):
        if(sum(petrol) < sum(distance)):
            return -1
        
        ans = 0
        balance = 0
        for i in range(n):
            balance = balance + petrol[i] - distance[i]
            if(balance < 0):
                ans = i+1
                balance = 0
        return ans

*/


//-------------------------------------------------------------------------------------------------------------------

// approach -> 3 TLE
struct petrolpump
{
    int petrol;
    int distance;
};

 int tour(petrolpump p[],int n)
    {
       int front = 0;
       int rear = 0;
       int bal = 0;
       
        while(front != n){
            
            if(bal+p[rear].petrol-p[rear].distance >= 0){
                bal+=p[rear].petrol;
                bal-=p[rear].distance;
                rear++;
                if((rear == n && front == 0) || rear == front){
                    return front;
                }
                
                else if(rear == n && front!=0){rear = 0;}
            }
            
            else{
                    front = rear+1;
                    rear = front;
                }
            
        }
        
        return -1;
    }
int main()
{   



    return 0;
}