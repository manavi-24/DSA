//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public: 
    int totalFruits(vector<int> &arr) {
        int count=0;
        int maxi=0;
        int start=0;
        int end=0;
        unordered_map<int, int>mpp;
        int n=arr.size();
        while(end<n){
            if(mpp[arr[end]]==0){
                count++;
            }
            mpp[arr[end]]++;
            if(count>2){
                if(mpp[arr[start]]==1){
                    count--;
                }
                mpp[arr[start]]--;
                start++;
            }
            if(count<=2){
                maxi=max(maxi,end-start+1);
            }
            end++;
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        int ans = ob.totalFruits(arr);

        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends