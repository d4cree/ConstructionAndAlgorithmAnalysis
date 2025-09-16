//Pronadji najkraci put
//Radimo kao neusmereni graf :)

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Graph{
    int V;
    vector<int> parents;
    vector<bool> visited;
    vector<vector<int>> adj_list;
};

void initialize_graph(Graph &g, const int V){
    g.V = V;
    g.parents.resize(V, -1);
    g.visited.resize(V, false);
    g.adj_list.resize(V);
}

void add_edges(Graph &g, const int u, const int v){
    g.adj_list[u].push_back(v);
    g.adj_list[v].push_back(u);
}

void BFS(Graph &g, int u, int v){
    queue<int> nodes;

    nodes.push(u);
    g.visited[u] = true;

    int pom;

    while(!nodes.empty()){
        pom = nodes.front();
        nodes.pop();

        if(pom == v)
            return;
        
        auto begin = g.adj_list[pom].begin();
        auto end = g.adj_list[pom].end();

        while(begin != end){
            if(!g.visited[*begin]){
                g.visited[*begin] = true;
                g.parents[*begin] = pom;
                nodes.push(*begin);
            }
            begin++;
        }
    }
}

void print_shortest_path(Graph &g, int u, int v){
    stack<int> path;

    if(g.parents[v] == -1){
        cout << "Ne postoji put!" << endl;
        return;
    }

    path.push(v);
    while(g.parents[v] != -1){
        v = g.parents[v];
        path.push(v);
    }

    int n = path.size();
    int x;

    while(n){
        x = path.top();
        path.pop();

        cout << x << " ";

        n--;
    }

    cout << endl;
}

int main(int argc, char **argv){

    return 0;
}