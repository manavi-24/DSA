class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int n=s.length();
        int maxLen=0;
        unordered_set<char>charSet;
        for(int right=0; right<n; right++){
            if(charSet.count(s[right])==0){
                charSet.insert(s[right]);
                maxLen=max(maxLen,right-left+1);
            }
            else{
                while(charSet.count(s[right])){
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);

            }
        }
        return maxLen;
        
    }
};