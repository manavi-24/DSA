//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int setBit(int n) {
        return n|n+1;
        // Write Your Code here
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        int ans = ob.setBit(N);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends