class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> ans(26, 0);
        for(char ch : s){
            ans[ch-'a']++;
        }

        for(char ch : t){
            ans[ch-'a']--;
        }

        for(int x : ans){
            if(x!=0) return false;
        }

        return true;
    }
};