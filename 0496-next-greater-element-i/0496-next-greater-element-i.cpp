class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_map<int, int>mp;
        stack<int>st;
        for(int i=n2-1; i>=0; i--){
            while(!st.empty() && nums2[i]>=st.top()){
                st.pop();
            }
            mp[nums2[i]]=st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        vector<int>result;
        for(int num:nums1){
            result.push_back(mp[num]);
        }
        return result;
        
    }
};