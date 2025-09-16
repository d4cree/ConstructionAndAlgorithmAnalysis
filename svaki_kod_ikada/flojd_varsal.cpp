#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Graph {
    int V;
    vector<vector<int>> distance;
};

void initialize(Graph &g, const int V){
    g.V = V;
    g.distance.resize(V, vector<int>(V, INT_MAX));
    for(int i = 0; i < V; i++){
        g.distance[i][i] = 0;
    }
}

void add_edges(Graph &g, const int u, const int v, const int w){
    g.distance[u][v] = w;
}

void flojd_varsal(Graph &g){
    for(int k = 0; k < g.V; k++){
        for(int i = 0; i < g.V; i++){
            for(int j = 0; j < g.V; j++){
                if(g.distance[i][k] != INT_MAX && g.distance[k][j] != INT_MAX){
                    g.distance[i][j] = min(g.distance[i][j], g.distance[i][k] + g.distance[k][j]);
                }
            }
        }
    }
}