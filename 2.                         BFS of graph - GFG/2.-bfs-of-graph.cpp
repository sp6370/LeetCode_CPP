// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<int> nodeQueue;
        
        vector<bool> visited(V, false); 
        nodeQueue.push_back(0);
        
        while(!nodeQueue.empty())
        {
            auto cNode = nodeQueue.front();
            nodeQueue.erase(nodeQueue.begin());
            
            visited[cNode]=true;
            result.push_back(cNode);
            
            for(int neighbourIndex: adj[cNode])
            {
                if(visited[neighbourIndex]!=true)
                {   
                    visited[neighbourIndex]=true;
                    nodeQueue.push_back(neighbourIndex);
                }
            }
            
        }
        
        return result;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends