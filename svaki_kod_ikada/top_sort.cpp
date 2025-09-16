//TOP_SORT + DFS (za pronalazenje ciklusa u grafu)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Graph{
    int V;
    vector<vector<int>> adj_list;
    vector<bool> visited;
    vector<int> in_deg;
    bool found;
};

void initialize(Graph &g, const int V){
    g.adj_list.resize(V);
    g.in_deg.resize(V, 0);
    g.found = false;
    g.visited.resize(V, false);
    g.V = V;
}

void add_edges(Graph &g, const int u, const int v){
    g.adj_list[u].push_back(v);

    g.in_deg[v]++;
}

void top_sort(Graph &g, vector<int> &result){
    queue<int> nodes;

    for(int i = 0; i < g.V; i++){
        if(g.in_deg[i] == 0)
            nodes.push(i);
    }

    int tmp;

    while(nodes.size()){
        tmp = nodes.front();
        nodes.pop();

        result.push_back(tmp);
        for(int node : g.adj_list[tmp]){
            g.in_deg[node]--;
            if(g.in_deg[node] == 0)
                nodes.push(node);
        }
    }
}

void DFS(Graph &g, int u, vector<int> &result, int start_node){
    if(g.visited[u] && u == start_node){
        result.push_back(u);
        g.found = true;
        return;
    }

    if(g.visited[u] && u != start_node){
        return;
    }

    result.push_back(u);
    g.visited[u] = true;

    auto begin = g.adj_list[u].begin();
    auto end = g.adj_list[u].end();
    while(begin != end){
        if(!g.found){
            DFS(g, *begin, result, start_node);
        }
        begin++;
    }
}

void find(Graph &g){
    vector<int> result;

    bool top_sorted = true;

    top_sort(g, result);

    for(int i = 0; i < g.V; i++){
        if(g.in_deg[i] > 0 && g.adj_list[i].size() > 0){
            top_sorted = false;
        }
    }

    if(top_sorted){
        for(int x : result){
            cout << x << " ";
        }
        cout << endl;
    }

    result.clear();
    for(int i = 0; i < g.V; i++){
        if(g.in_deg[i] > 0){
            DFS(g, i, result, i);

            for(int x : result)
                cout << x << " ";
            cout << endl;
        }

    }
}