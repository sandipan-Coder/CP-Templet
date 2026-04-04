#include<bits/stdc++.h>
using namespace std;

// This Algorithm is usefull for find single source shortest path.
// This Algorithm is not work in Negative edge cycle Graph.

vector<int> dijkstra_algo(int n, int src, vector<pair<int, int>> adj[]) {

    vector<int> dist(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dist[src] = 0;

    while(!pq.empty()) {

        auto it = pq.top();
        pq.pop();

        int cost = it.first;
        int node = it.second;

        for(auto nei: adj[node]) {
            int neiNode = nei.first;
            int wt = nei.second;

            if(cost + wt < dist[neiNode]) {
                dist[neiNode] = cost + wt;
                pq.push({dist[neiNode], neiNode});
            }
        }
    }

    return dist;
}


int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> adj[n];

    vector<vector<int>> edges;

    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[3];

        // This is for Undirected Graph
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});

        // This is for Directed Graph
        adj[u].push_back({v, wt});
    }

    dijkstra_algo(n, 0, adj);
}