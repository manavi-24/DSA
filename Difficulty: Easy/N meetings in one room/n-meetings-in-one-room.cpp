//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int> start, vector<int> end) {
        // Your code here
        int n  = start.size() ;
        vector<pair<int, int>>v ;
        for(int i = 0; i<n; i++){
            v.push_back({end[i] , start[i]}) ;
        }
        
        sort(v.begin() , v.end()) ;
        
        int meetingsCnt  = 1 ;
        int endTime  = v[0].first ;
        
        for(int i = 1; i<n; i++){
            
            if( v[i].second > endTime){ // startTime > endTIme
                meetingsCnt++ ;
                endTime = v[i].first ;
            }
        }
        return meetingsCnt ;
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends