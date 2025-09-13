//2. zadati su linkovi ka stranicama (usmerene grane), naći prosečan broj klikova koji je potreban za svaku
// stranicu ako uzmemo u obzir da ne postoje linkovi na samog sebe kao ni stranice koje nisu povezane

#include <iostream>
#include <vector>
#include <climits>

using namespace std;


struct Graph{
    vector<vector<int>> distance;
    int V;
};

void initialize_graph(Graph &g, const int V){
    g.V = V;
    g.distance.resize(V, vector<int>(V, INT_MAX));
    for(int i = 0; i < V; i++){
        g.distance[i][i] = 0;
    }
}

void add_edge(Graph &g, const int u, const int v, int weight){
    g.distance[u][v] = weight;
}



void flojd_varsal(Graph &g){
    for(int k = 0; k < g.V; k++){
        for(int i = 0; i < g.V; i++){
            for(int j = 0; j < g.V; j++){
                if(g.distance[i][k] != INT_MAX && g.distance[k][j] != INT_MAX)
                    g.distance[i][j] = min(g.distance[i][j], g.distance[i][k] + g.distance[k][j]);
            }
        }
    }

}

int main(int argc, char** argv){
    Graph g;

    initialize_graph(g, 4);

    add_edge(g, 0, 1, 1);
    add_edge(g, 0, 2, 1);
    add_edge(g, 1, 2, 1);
    add_edge(g, 2, 3, 1);
    add_edge(g, 3, 0, 1);

    flojd_varsal(g);

    for(int i = 0; i < g.V; i++){
        int sum = 0; int count = 0;
        for(int j = 0; j < g.V; j++){
            if(i != j && g.distance[i][j] != INT_MAX){
                sum += g.distance[i][j];
                count++;
                cout << sum << " " << count << endl;
            }
        }

        if(count > 0){
            double avg = double(sum) / count;
            cout << "Stranica " << i << ": prosek " << avg << endl; 
        
        } else {
            cout << "Greska!" << endl;
        }
    }

    return 0;
}