//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        
        for (int i = pre_exp.size() - 1; i >= 0; i--) {
            if ((pre_exp[i] >= 'a' && pre_exp[i] <= 'z') ||
                (pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || 
                (pre_exp[i] >= '0' && pre_exp[i] <= '9')) {
                st.push(string(1, pre_exp[i]));
            } else {
                // Ensure the stack has at least two elements before popping
                if (st.size() < 2) {
                    cerr << "Invalid prefix expression: Not enough operands for the operator '" << pre_exp[i] << "'" << endl;
                    return "";
                }

                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                
                // Push the combined postfix expression back to the stack
                st.push(t1 + t2 + pre_exp[i]);
            }
        }
        
        // After processing, there should be exactly one element in the stack
        if (st.size() != 1) {
            cerr << "Invalid prefix expression: Remaining elements in the stack after processing" << endl;
            return "";
        }
        
        return st.top();
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToPost(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends