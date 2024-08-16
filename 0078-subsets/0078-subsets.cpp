class Solution {
public:
    void function(int ind, vector<int>&ds, vector<int>&nums, int n, vector<vector<int>>&result){
        if(ind==n){
            result.push_back(ds);
            return;
        }
        ds.push_back(nums[ind]);
        function(ind+1, ds, nums, n, result);
        
        ds.pop_back();
        function(ind+1, ds, nums, n, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>ds;
        vector<vector<int>>result;
        int n=nums.size();
        function(0, ds, nums, n, result);
        return result;


        
    }
};