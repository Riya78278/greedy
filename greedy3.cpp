// Maximum Meetings in One Room

#include <iostream>
using namespace std;

class Solution {
  public:
    vector<int> maxMeetings(int N, vector<int> &S, vector<int> &F) {
        int n=S.size();
        vector<pair<pair<int,int>,int>>meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({{F[i],S[i]},i+1});
        }
        sort(meetings.begin(),meetings.end());
        
        vector<int>ans;
        int lastend=-1;
        
        for(auto &m: meetings){
            int e=m.first.first;
            int s=m.first.second;
            int index=m.second;
            
            if(s>lastend){
                ans.push_back(index);
                lastend=e;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
