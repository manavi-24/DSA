class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int total=0;
        int maxleft=0;
        int maxright=0;

        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft){
                    maxleft=height[left];
                }
                else{
                    total+=maxleft-height[left];
                }
                left++;
            }
            else{
                if(height[right]>=maxright){
                    maxright=height[right];
                }
                else{
                    total+=maxright-height[right];
                }
                right--;
            }
        }
        return total;

        
    }
};