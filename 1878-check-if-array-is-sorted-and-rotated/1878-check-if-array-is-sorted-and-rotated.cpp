class Solution {
public:
    bool check(vector<int>& nums) {
        /*for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                while(nums[j]<nums[i]){
                    if(nums[j+1]<nums[i+1]){
                        return false;
                    }
                }
                return true;
            }
        }
    return true;
    }*/
     int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
};