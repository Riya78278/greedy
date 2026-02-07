// Shop in Candy Store

#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        //sort karke two pointer
        sort(prices.begin(),prices.end());
        int start = 0;
        int low_cost = 0;
        int high_cost= 0;
        int end=  prices.size()-1;
        while(start<=end){
            int j = k;
            low_cost +=  prices[start];
            end -= j;
            start++;
        } 
        start = 0 ;
        end = prices.size()-1;
        while(start<=end){
            int j = k;
            high_cost += prices[end];
            start += j;
            end--;
        }
        vector<int>a;
        a.push_back(low_cost);
        a.push_back(high_cost);
        return a;
    }
};
