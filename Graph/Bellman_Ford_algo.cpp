#include<bits/stdc++.h>
using namespace std;

// This Algorithm is usefull for find single source shortest path.
// This Algorithm can detect Negative edge cycle of a Graph.

vector<int> bellmonFord(int n, int src, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1, 1e8);
    dist[src] = 0;

    for(int i = 0; i < n-1; i++) {
        for(auto it: edges) {

            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    // If Negative edge cycle is present then after (n - 1) iteration we do one more 
    //iteration if still the cost of any node is reduce then there is a negative edge cycle 
    //in the given graph.
    for(auto it: edges) {

        int u = it[0];
        int v = it[1];
        int wt = it[2];

        if(dist[u] + wt < dist[v])
            cout << "Negative Edge cycle is present.";
    }

    return dist;
}