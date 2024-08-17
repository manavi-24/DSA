//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    public:
    void findsubsets(int ind, vector<int>&arr, int n,vector<int>&ans, int sum){
        if(ind==n){
            ans.push_back(sum);
            return;
        }
        findsubsets(ind+1, arr, n,ans, sum+arr[ind]);
        findsubsets(ind+1, arr, n,ans, sum);
    }

    vector<int> subsetSums(vector<int> arr, int n) {
        vector<int>ans;
        findsubsets(0, arr, n, ans, 0);
        sort(ans.begin(), ans.end());
        return ans;
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
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends