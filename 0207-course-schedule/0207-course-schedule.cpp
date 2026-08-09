class Solution {
	public:	
	bool dfsCheck(vector<vector<int>> &graph, vector<int> &vis, vector<int> &pathVis,
	int node) {
		vis[node] = 1;
		pathVis[node] = 1;
		
		for (auto it : graph[node]) {
			if (!vis[it]) {
				if (dfsCheck(graph, vis, pathVis, it))
					return true;
			}
			else if (pathVis[it]) {
				return true;
			}
		}
		pathVis[node] = 0;
		return false;
	}
	
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        int V = numCourses;
		vector<int> vis(V, 0);
		vector<int> pathVis(V, 0);
		vector<vector<int>> graph(V);
		for (auto x: prerequisites) {
			int u = x[0];
			int v = x[1];
			
			graph[v].push_back(u);
		}
		
		for (int i = 0; i<V; i++) {
			if (vis[i] == 0) {
				if (dfsCheck(graph, vis, pathVis, i))
					return false;
			}
		}
		
		return true;
	}
};
