class Solution {
public:
    void findcombo(int ind, int target, vector<int>&candidates, vector<vector<int>>&result, vector<int>ds){
        if(ind==candidates.size()){
            if(target==0){
                result.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            findcombo(ind, target-candidates[ind], candidates, result, ds);
            ds.pop_back();

        }
        findcombo(ind+1, target, candidates, result, ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>result;
        findcombo(0, target, candidates,result, ds);
        return result;
        
    }
};