class Solution {
public:
    void findCombinations(int index, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &ds){
        if(index == candidates.size()){
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }
    
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            findCombinations(index+1, candidates, target-candidates[index], ans, ds);
            ds.pop_back();
        }

        int next = index + 1;

        while(next < candidates.size() && candidates[next] == candidates[index]) {
            next++;
        }

        findCombinations(next, candidates, target, ans, ds);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());

        findCombinations(0, candidates, target, ans, ds);
        return ans;
    }
};