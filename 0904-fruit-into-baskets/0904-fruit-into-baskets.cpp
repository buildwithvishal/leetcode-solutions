class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0;
        int maxfruits = 0;
        unordered_map<int, int> mp;

        for(int r = 0; r<n; r++){
            mp[fruits[r]]++;

            if(mp.size()>2){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
                l++;
            }

            if(mp.size()<=2){
                maxfruits = max(maxfruits, r-l+1);
            }
        }

        return maxfruits;
    }
};