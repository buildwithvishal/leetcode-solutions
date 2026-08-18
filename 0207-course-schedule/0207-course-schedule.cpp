class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> inDegree(n, 0);
        vector<vector<int>> graph(n);

        for(auto &x: prerequisites){
            int u = x[0];
            int v = x[1];
            graph[v].push_back(u);
        } 

        for(int i = 0; i<n; i++){
            for(auto it : graph[i]){
                inDegree[it]++;
            }
        }

        queue<int> q;

        for(int i = 0; i<n; i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                inDegree[it]--;
                if(inDegree[it] == 0){
                    q.push(it);
                }
            }
        }
        for(int i = 0; i<n; i++){
            if(inDegree[i]!= 0){
                return false;
            }
        }

        return true;  
    }
};