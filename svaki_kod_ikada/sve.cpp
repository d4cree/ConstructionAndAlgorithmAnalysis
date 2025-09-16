#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <set>
#include <cmath>
#include <climits>
#include <stack>

using namespace std;

struct Graph {
    vector<vector<int>> adj_list;
    int V;
    stack<int> stack;
    vector<int> ojler;
    vector<int> in_deg;
    vector<int> out_deg;
};

void initialize(Graph &g, const int V){
    g.adj_list.resize(V);
    g.V = V;
    g.in_deg.resize(V, INFINITY);
    g.out_deg.resize(V, INFINITY);
}

void add_edges(Graph &g, const int u, const int v){
    g.adj_list[u].push_back(v);

    g.out_deg[u]++;
    g.in_deg[v]++;
}

void hierholzer(Graph &g){
    int start = 0;

    for(int i = 0; i < g.V; i++){
        if(g.out_deg[i] == g.in_deg[i]+1){
            start = i;
            break;
        }
        
        if(g.out_deg[i] > 0){
            start = i;
        }
    }

    g.stack.push(start);

    int v = start;
    int tmp;

    while(!g.stack.empty()){
        if(g.adj_list[v].size()){
            g.stack.push(v);
            
            tmp = g.adj_list[v].back();
            g.adj_list[v].pop_back();

            v = tmp;
        } else {
            g.ojler.push_back(v);
            v = g.stack.top();
            g.stack.pop();
        }
    }
}
