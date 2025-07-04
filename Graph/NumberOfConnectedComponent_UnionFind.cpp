class DSU{
    public:
    vector<int> rank, parent;

    DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<=n;i++){
            parent[i] =i;
        }
    }

    int find(int node){
        int current = node;
        while(current != parent[current]){
            parent[current] = parent[parent[current]];
            current = parent[current];
        }
        return current;
    }

    bool unionSet(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return false;
        if(rank[pv] > rank[pu]){
            // swap(pu,pv);
            parent[pu] = pv;
        }
        else if(rank[pu] > rank[pv]){
            parent[pv] =pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
        // parent[pv] = pu;
        // rank[pu]+=rank[pv];
        return true;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty())
        {
            return 0;
        }
        int n = isConnected.size();
        DSU dsu(n);

        for(int i=0;i<isConnected.size();++i)
        {
            for(int j = 0;j<isConnected[0].size();++j){
                if(isConnected[i][j]){
                    if(dsu.unionSet(i,j))
                    {
                        n--;
                    }
                }
            }
        }
        // vector<bool> visited(n, false);
        // int provinces =0;
        // for(int i=0;i< visited.size();i++)
        // {
        //     if(!visited[i])
        //     {
        //         provinces++;
        //         dfs(isConnected, visited, i);
        //     }
        // }
        return n;
    }

    // void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int idx)
    // {
    //     visited[idx] = true;
    //     for(int i=0; i<visited.size(); i++)
    //     {
    //         if(i != idx && isConnected[idx][i] && !visited[i])
    //         {
    //             dfs(isConnected, visited, i);
    //         }
    //     }
    // }
};
