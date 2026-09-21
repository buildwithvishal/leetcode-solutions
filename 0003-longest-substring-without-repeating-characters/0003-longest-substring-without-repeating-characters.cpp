class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int maxlen = 0;
        unordered_map<char, int> mp;

        for(int r= 0; r<n; r++){
            if(mp.find(s[r])!= mp.end()){
                l = max(l, mp[s[r]]+1);
            }
            mp[s[r]] = r;
            maxlen = max(r-l+1, maxlen);
        }

        return maxlen;

    }
};