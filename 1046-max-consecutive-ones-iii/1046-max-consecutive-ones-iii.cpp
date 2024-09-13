class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int right=0;
        int left=0;
        int zeroes=0;
        int maxlen=0;
        int n=nums.size();
        while(right<n){
            if(nums[right]==0){
                zeroes++;
            }
            if(zeroes>k){
                if(nums[left]==0){
                    zeroes--;
                }
                left++;
            }
            maxlen=right-left+1;
            right++;
        }
        return maxlen;
        
    }
};