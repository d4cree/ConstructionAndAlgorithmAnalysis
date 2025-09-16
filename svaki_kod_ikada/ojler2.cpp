#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj_list;
    stack<int> stack;
    vector<int> euler_path;
};

void initialize(Graph &g, const int V){
    g.V = V;
    g.adj_list.resize(V);
}

void add_edges(Graph &g, const int u, const int v){
    g.adj_list[u].push_back(v);
}

void heirholzer(Graph &g){
    //Pocetni cvor - izlazni = ulazni + 1;
    //Zavrsni cvor - ulazni = izlazni + 1;

    g.stack.push(0);
    int v = 0;
    int tmp;

    while(!g.stack.empty()){
        if(g.adj_list[v].size()){
            g.stack.push(v);

            tmp = g.adj_list[v].back();
            v = tmp;
        } else {
            g.euler_path.push_back(v);
            v = g.stack.top();
            g.stack.pop();
        }
    }
}