#include <bits/stdc++.h>
using namespace std;


vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{

    vector<pair<int, int>> adj[n+1];
    for(int i = 0; i < m; i++) {

        auto it = g[i];
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<pair<pair<int, int>, int>> ans;

    priority_queue<pair<int, pair<int, int>>, 
                vector<pair<int, pair<int, int>>>,
                greater<pair<int, pair<int, int>>>> pq;
                
    vector<bool> vis(n+1, false);

    pq.push({0, {1, -1}});

    while(!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        int cost = it.first;
        int node = it.second.first;
        int parent = it.second.second;

        if(vis[node])
            continue;
        
        vis[node] = true;
        if(parent != -1)
            ans.push_back({{parent, node}, cost});
        
        for(auto nei: adj[node]) {
            int neiNode = nei.first;
            int wt = nei.second;

            if(!vis[neiNode])
                pq.push({wt, {neiNode, node}});
        }
    }
    
    return ans;
}