class Solution {
public:
    void bfs(int room, vector<vector<int>>& rooms, vector<bool>& vis){
        vis[room] = true;
       for(int key : rooms[room]){
        if(!vis[key]){
            bfs(key, rooms, vis);
        }
       }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n, false);
        bfs(0, rooms, vis);
        for(int i = 0; i < n; i++){
            if(!vis[i])return false;
        }
        return true;
    }
};