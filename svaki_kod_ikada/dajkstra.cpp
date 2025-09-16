#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct compare{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2){
        return p1.first > p2.first;
    }
};

struct Graph {
    int V;
    vector<vector<pair<int, int>>> adj_list;
    vector<int> distances;
    vector<bool> path_found;
};

void initialize(Graph &g, int V){
    g.V = V;
    g.adj_list.resize(V);
    g.distances.resize(V, INFINITY);
    g.path_found.resize(V, false);
}

void add_edges(Graph &g, const int u, const int v, const int w){
    g.adj_list[u].push_back(make_pair(v, w));
    g.adj_list[v].push_back(make_pair(u, w));
}

int dijkstra(Graph &g, int u, int v){
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;

    g.distances[u] = 0;
    heap.push({0, u});

    while(!heap.empty()){
        auto [cost, tmp] = heap.top();
        heap.pop();

        if(g.path_found[tmp])
            continue;
        
        g.path_found[tmp] = true;

        if(tmp == v)
            return cost;
        
        for(auto[node, weight] : g.adj_list[tmp]){
            int new_cost = weight + cost;
            if(new_cost < g.distances[node]){
                g.distances[node] = new_cost;
                heap.push({new_cost, node});
            }
        }
    }
    return -1;
}