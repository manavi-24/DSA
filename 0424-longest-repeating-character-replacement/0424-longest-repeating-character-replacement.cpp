class Solution {
public:
     int characterReplacement(string s, int k) {
        unordered_map<char, int> mpp;
        int ans = 0;
        int left = 0;
        int right = 0;
        int maxi = 0;

        for (right = 0; right < s.size(); right++) {
            mpp[s[right]]++;
            maxi = max(maxi, mpp[s[right]]);

            if ((right - left + 1) - maxi > k) {
                mpp[s[left]]--;
                left++;
            } else {
                ans = max(ans, (right - left + 1));
            }
        }

        return ans;
    }
};
