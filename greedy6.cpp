// Minimum Cost of ropes


#include <iostream>
using namespace std;

class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int, vector<int>, greater<int>> pq;  
        
        if(arr.size()==1){
            return 0;
        }
        if(arr.size()==2){
            return arr[0]+arr[1];
        }
        for(int i=0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        int ans=0;
        while(pq.size()>=2){
            int top=pq.top();
            pq.pop();
            int sectop=pq.top();
            pq.pop();
            int cost=top+sectop;
            pq.push(cost);
            ans=ans+cost;
        }
        
        return ans;
    }
};
