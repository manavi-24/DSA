class Solution {
public:
    int func(vector<int>& nums, int goal) {
        if (goal<0)return 0;
        int n=nums.size();
        int left=0;
        int right=0;
        int count=0;
        int sum=0;
        while(right<n){
            sum+=(nums[right]%2);
            while(sum>goal){
                sum-=(nums[left]%2);
                left++;
            }

            count=count+(right-left+1);
            right++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int goal){
        int x=func(nums, goal);
        int y=func(nums, goal-1);
        return x-y;
    }
    
};