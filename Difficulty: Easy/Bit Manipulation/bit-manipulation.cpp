//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
        int getbit = (num >> (i-1)) & 1;
        int setbit=num|(1<<(i-1));
        int clearbit=num&~(1<<(i-1));
        cout<<getbit<<" "<<setbit<<" "<<clearbit;
        // your code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends