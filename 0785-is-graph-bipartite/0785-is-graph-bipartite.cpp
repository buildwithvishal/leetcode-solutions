class Solution {

    bool check(vector<vector<int>>& graph, vector<int>& vis, int n, int start){
        queue<int> q;
        q.push(start);
        vis[start] = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(int it: graph[node]){
                if(vis[it] == -1){
                    vis[it] = !vis[node];
                    q.push(it);

                }

                else if(vis[it] == vis[node]){
                    return false;
                }
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i =0; i<n; i++){
            if(vis[i]==-1){
                if(check(graph, vis, n, i)== false) return false;
            }
        }

        return true;
    }
};