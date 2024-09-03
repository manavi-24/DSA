class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int ans=0;
        const int MOD=1e9+7;
        int n=arr.size();
        vector<int>pse(arr.size());
        vector<int>nse(arr.size());
        stack<int>st;
        for(int i=0; i<n; i++){
            if(st.empty()){
                pse[i]=-1;
                st.push(i);
                continue;
            }
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            pse[i]=st.empty()?-1:st.top();
            st.push(i);
        }
        st=stack<int>();
        for(int i=n-1; i>=0; i--){
            if(st.empty()){
                nse[i]=n;
            }
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                nse[i]=st.empty()?n:st.top();
            }
            st.push(i);
        }
        for(int i=0; i<n; i++){
            long long l=i-pse[i];
            long long r=nse[i]-i;
            long long m=(l%MOD * r%MOD) % MOD;
            ans=(ans+(arr[i]*m)%MOD)%MOD;

        }
        return ans;

    }
};