Directed Graph Cycle
Difficulty: MediumAccuracy: 27.88%Submissions: 521K+Points: 4
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Examples:

Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 0], [2, 3]]

Output: true
Explanation: The diagram clearly shows a cycle 0 → 2 → 0

Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]

Output: false
Explanation: no cycle in the graph
Constraints:
1 ≤ V, E ≤ 105
u ≠ v





class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) 
    {
        // code here
        vector<int>vis(V,0);
        
        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];   
            adj[u].push_back(v);
        }
        
        for(int i = 0;i<V;i++)
        {
            if(traversal(vis,adj,i))
            {
                return true;
            }
        }
        return false;
    }
    
    bool traversal(vector<int>&vis,vector<vector<int>>&adj,int index)
    {
        vis[index] = 1;
        for(auto it : adj[index])
        {
            if(vis[it] == 0)
            {
                if(traversal(vis,adj,it)) return true;
            }
            else if(vis[it] == 1)
            {
                return true;
            }
        }
        vis[index] = 2;
        return false;
        
    }
    
};
