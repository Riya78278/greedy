// Check if it is possible to survive on Island

#include <iostream>
using namespace std;

class Solution {
  public:
    int minimumDays(int S, int N, int M) {
        // code here
        if(M>N){
            return -1;
        }
        if(S>=7 && (N-M)*6 < M) return -1;
        int sunday=S/7;
        int buyday=S-sunday;
        
        int totalfood=S*M;
        int ans=0;
        
        if(totalfood %N==0){
            ans=totalfood/N;
        }else{
            ans=totalfood/N+1;
        }
        if(ans <= buyday){
            return ans;
        }
        return -1;
    }
};
