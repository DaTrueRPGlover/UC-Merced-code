#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, d, w;
};

void bellmanFord(const vector<Edge>& e, int V, int E) {
    vector<int> dist(V, INT_MAX);
    dist[0] = 0;

    for (int i = 1; i < V; ++i) {
        for (const Edge& edge : e) {
            int u = edge.src;
            int v = edge.d;
            int w2 = edge.w;

            if (dist[u] != INT_MAX && dist[u] + w2 < dist[v]) {
                dist[v] = dist[u] + w2;
            }
        }
    }

    bool negCycle = false;
    for (const Edge& edge : e) {
        int u = edge.src;
        int v = edge.d;
        int w2 = edge.w;

        if (dist[u] != INT_MAX && dist[u] + w2 < dist[v]) {
            negCycle = true;
            break;
        }
    }

    if (negCycle) {
        cout << "FALSE\n";
    } else {
        cout << "TRUE\n";
        for (int i = 0; i < V; ++i) {
            if (dist[i] == INT_MAX) {
                cout << "INFINITY\n";
            } else {
                cout << dist[i] << endl;
            }
        }
    }
}

int main() {
    int V, E;
    cin >> V;
    cin >> E;

    vector<Edge> e(E);
    for (int i = 0; i < E; ++i) {
        cin >> e[i].src >> e[i].d >> e[i].w;
    }

    bellmanFord(e, V, E);

    return 0;
}
