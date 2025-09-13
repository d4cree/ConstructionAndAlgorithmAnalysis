/*3 Stanice   (dijkstra)
Pera nema para hoce da stigne do odredista najjeftinije moguce pomozi mu.
u gradu ima n stanica i izmedju tih n stanica ima m linija i svaka linija ima svoju cenu.
npr ako oces da ides do B a ti se nalazis na stanici A i cena koju si platio do stanice A je bila 1000din,
a cena linije od A do B je 1200, doplatices samo razliku tj 200din.
Ako si u A i platio si 1000din a cena karte od A do B je 800din neces nista doplatiti.
Sve linije vozila su u oba smera.

ulaz: dva broja n i m pa onda m linija prevoza izmedju od a do b i cenja puta c

izlaz: najjeftiniji put od 1 do n

test primer:
5 5
1 2 60
4 1 120
5 3 70
2 3 80
4 5 150

izlaz 
80
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int, int>>> susedi;
    vector<int> distance;
    vector<bool> path_found;
};

struct compare{
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2){
        return p1.first > p2.first;
    }
};

void initialize_graph(Graph &g, const int V){
    g.V = V;
    g.susedi.resize(V+1);
    g.distance.resize(V+1, INFINITY);
    g.path_found.resize(V+1, false);
}

void add_edges(Graph &g, const int u, const int v, const int weight){
    g.susedi[u].push_back(make_pair(v, weight));
    g.susedi[v].push_back(make_pair(u, weight));
}

int dijsktra(Graph &g, int u, int v){
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> heap;

    g.distance[u] = 0;

    heap.push({0, u});

    while(!heap.empty()){
        auto [cost, tmp] = heap.top();
        heap.pop();
        if(g.path_found[tmp])
            continue;
        
        g.path_found[tmp] = true;
        
            if(tmp == v)
                return cost;

        for(auto [x, y] : g.susedi[tmp]){
            int new_cost = max(cost, y);
            if(new_cost < g.distance[x]){
                g.distance[x] = new_cost;
                heap.push({new_cost, x});
            }
        }
    }

    return -1;
}

int main(){
    Graph g;
    initialize_graph(g, 5);

    add_edges(g, 1, 2, 60);
    add_edges(g, 4, 1, 120);
    add_edges(g, 5, 3, 70);
    add_edges(g, 2, 3, 80);
    add_edges(g, 4, 5, 150);

    cout << dijsktra(g, 1, 5) << endl;

    return 0;
}