// N meetings in one room
#include <iostream>
using namespace std;

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n=start.size();
        vector<pair<int,int>>meetings;
        for(int i=0;i<n;i++){
            meetings.push_back({end[i],start[i]});
        }
        sort(meetings.begin(),meetings.end());
        
        int count=0;
        int lastend=-1;
        
        for(auto &m:meetings){
            int e=m.first;
            int s=m.second;
            
            if(s>lastend){
                count++;
                lastend=e;
            }
        }
        return count;
    }
};