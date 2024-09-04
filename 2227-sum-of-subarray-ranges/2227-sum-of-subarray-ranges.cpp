class Solution {
public:
    vector<int>pse(vector<int>&nums){
        stack<int>st;
        st.push(-1);
        vector<int>ans(nums.size(), -1);
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && st.top()!=-1 && nums[st.top()]>=nums[i]){
                st.pop();

            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nse(vector<int>&nums){
        stack<int>st;
        st.push(-1);
        vector<int>ans(nums.size(), -1);
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && st.top()!=-1 && nums[st.top()]>nums[i]){
                st.pop();

            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubArrMin(vector<int>&nums){
        vector<int>prev=pse(nums);
        vector<int>next=nse(nums);
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            int previ=prev[i];
            int nexti=next[i]==-1?nums.size():next[i];
            int left=i-previ;
            int right=nexti-i;
            long long currSize=left*right;
            long long val=nums[i]*currSize;
            sum+=val;

        }
        return sum;
    }
    vector<int>pge(vector<int>&nums){
        stack<int>st;
        st.push(-1);
        vector<int>ans(nums.size(), -1);
        for(int i=0; i<nums.size(); i++){
            while(!st.empty() && st.top()!=-1 && nums[st.top()]<=nums[i]){
                st.pop();

            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int>nge(vector<int>&nums){
        stack<int>st;
        st.push(-1);
        vector<int>ans(nums.size(), -1);
        for(int i=nums.size()-1; i>=0; i--){
            while(!st.empty() && st.top()!=-1 && nums[st.top()]<nums[i]){
                st.pop();

            }
            ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    long long sumSubArrMax(vector<int>&nums){
        vector<int>prev=pge(nums);
        vector<int>next=nge(nums);
        long long sum=0;
        for(int i=0; i<nums.size(); i++){
            int previ=prev[i];
            int nexti=next[i]==-1?nums.size():next[i];
            int left=i-previ;
            int right=nexti-i;
            long long currSize=left*right;
            long long val=nums[i]*currSize;
            sum+=val;

        }
        return sum;
    }
    long long subArrayRanges(vector<int>& nums) {
        return sumSubArrMax(nums)-sumSubArrMin(nums);
        
    }
};