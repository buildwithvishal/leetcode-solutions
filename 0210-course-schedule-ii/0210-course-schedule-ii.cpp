class Solution {
public:
    bool dfsCheck(int n, vector<vector<int>>& graph, vector<int> &vis,
    vector<int> &pathvis, vector<int> &ans, int node){
        vis[node] = 1;
        pathvis[node] = 1;
        

        for (auto it : graph[node]) {
			if (!vis[it]) {
				if (dfsCheck(n, graph, vis, pathvis, ans, it)){
                    return true;
                }
			}
			else if (pathvis[it]) {
				return true;
			}
		}
		pathvis[node] = 0;
        ans.push_back(node);
		return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> vis(n, 0);
        vector<int> pathvis(n, 0);
        vector<int> ans;
        vector<vector<int>> graph(n);
        for(auto x: prerequisites){
            int u = x[0];
            int v = x[1];

            graph[v].push_back(u);
        }

        for(int i = 0; i<n; i++){
            if(vis[i] == 0){
                if (dfsCheck(n, graph, vis, pathvis, ans, i))
					return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};