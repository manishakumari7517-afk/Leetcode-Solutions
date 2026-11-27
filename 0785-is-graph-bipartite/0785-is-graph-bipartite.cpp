class Solution {
public:
bool bfs(int src, vector<vector<int>>& adj, vector<int>& color){
            queue<pair<int, int>> q;
            color[src] = 0;
            q.push({src, 0});
            while(q.size() > 0){
                pair<int, int> front = q.front();
                q.pop();
                for(int node : adj[front.first]){
                    if(color[node] == -1){
                        color[node] = 1- front.second;
                        q.push({node, color[node]});
                    }
                    else if(color[node] == front.second)return false;
                    if(!color[node]){
                      q.push({node, color[node]});
                      color[node] = 1 - front.second;
                    }
                }
            }
            return true;
        }
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
                vector<int> color(n, -1);
                for(int i = 0; i < n; i++){
                    if(color[i] == -1){
                        if(!bfs(i, adj, color))return false;
                    }
                }
                return true;
    }
};