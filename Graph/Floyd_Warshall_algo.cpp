#include<bits/stdc++.h>
using namespace std;

// This Algorithm is usefull for find Multi_Source shortest path.
// This Algorithm can detect negative Edge Cycle.

void Floyd_Warshall_algo(int n, vector<vector<int>>& edges) {
        
    vector<vector<int>> dist(n, vector<int>(n, 1e8));

    // For node_i -> node_i distance = 0;
    for(int i = 0; i < n; i++)
        dist[i][i] = 0;

    // Creating the cost Matrix
    for(auto it: edges) {
        int u = it[0];
        int v = it[1];
        int wt = it[2];

        // This is for Undirected Graph
        dist[u][v] = wt;
        dist[v][u] = wt;

        // This is for Directed Graph
        dist[u][v] = wt;
    }


    // Floyd Warshall Algorithm Implementation
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                
                if(dist[i][k] != 1e8 && dist[k][j] != 1e8)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // If Negative Edge cycle is present then (dist[i][i] < 0)
    for(int i = 0; i < n; i++) {
        if(dist[i][i] < 0)
            cout << "Negative Edge Cycle is Present.";
    }

}