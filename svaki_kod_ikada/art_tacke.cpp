#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Graph{
    int V;
    vector<vector<int>> adj_list;
    vector<int> parents;
    vector<bool> visited;
    int time;
    vector<int> times;
    vector<int> lower_times;
    set<int> articulation_points;
};

void initialize(Graph &g, const int V){
    g.V = V;
    g.adj_list.resize(V);
    g.lower_times.resize(V, -1);
    g.times.resize(V, -1);
    g.parents.resize(V, -1);
    g.visited.resize(V, false);
    g.time = 0;
}

void add_edges(Graph &g, const int u, const int v){
    g.adj_list[u].push_back(v);
    g.adj_list[v].push_back(u);
}

void DFS(Graph &g, int u){
    g.visited[u] = true;
    g.times[u] = g.lower_times[u] = g.time;
    g.time++;
    int children = 0;

    auto begin = g.adj_list[u].begin();
    auto end = g.adj_list[u].end();
    while(begin != end){
        if(!g.visited[*begin]){
            g.parents[*begin] = u;
            DFS(g, *begin);

            children++;
            g.lower_times[u] = min(g.lower_times[u], g.lower_times[*begin]);

            if(g.parents[u] == -1 && children > 1)
                g.articulation_points.insert(u);

            if(g.parents[u] != -1 && g.times[u] <= g.lower_times[*begin])
                g.articulation_points.insert(u);
        } else if(*begin != g.parents[u]) {
            g.lower_times[u] = min(g.lower_times[u], g.times[*begin]);
        }
        begin++;
    }
}

void print_set(Graph &g){
    DFS(g, 3);

    for(int x : g.articulation_points)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main(){
    return 0;
}