class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty())
        {
            return 0;
        }
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces =0;
        for(int i=0;i< visited.size();i++)
        {
            if(!visited[i])
            {
                provinces++;
                dfs(isConnected, visited, i);
            }
        }
        return provinces;
    }

    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int idx)
    {
        visited[idx] = true;
        for(int i=0; i<visited.size(); i++)
        {
            if(i != idx && isConnected[idx][i] && !visited[i])
            {
                dfs(isConnected, visited, i);
            }
        }
    }
};
