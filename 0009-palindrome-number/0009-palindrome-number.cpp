    class Solution {
    public:
        bool isPalindrome(int n) {
        int ld;
        int dupl=n;
        long int rd=0;
        while(n>0){
            ld=n%10;
            rd=rd*10+ld;
            n=n/10;}
        if(dupl==rd){
            return true;
        }
        else{
            return false;
        }
        
            
        }
    };