#include <iostream>
#include <list>
#include <stack>
using namespace std;
class SCC {
    int V;
    list<int>* adj;
    void SCCfillID(int v, bool tvs[], stack<int>& s);
    void SSCDFS(int v, bool tvs[], int n, int ar[]);

public:
    SCC(int V);
    void connect(int v, int w);
    void printSCCs(int n, int arr[]);
    SCC transpose();
};
SCC::SCC(int V) {
    this->V = V;
    adj = new list<int>[V];
}
void SCC::SSCDFS(int v, bool tvs[], int n,
    int arr[]) {
    tvs[v] = true;
    arr[v] = n;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!tvs[*i])
            SSCDFS(*i, tvs, n, arr);
}

SCC SCC::transpose() {
    SCC g(V);
    for (int v = 0; v < V; v++) {
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            g.adj[*i].push_back(v);
        }
    }
    return g;
}
void SCC::connect(int v, int w) {
    adj[v].push_back(w);
}
void SCC::SCCfillID(int v, bool tvs[],
    stack<int>& s) {
    tvs[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!tvs[*i])
            SCCfillID(*i, tvs, s);
    s.push(v);
}
void SCC::printSCCs(int n, int arr[]) {
    stack<int> s;
    bool* tvs = new bool[V];
    for (int i = 0; i < V; i++)
        tvs[i] = false;
    for (int i = 0; i < V; i++)
        if (tvs[i] == false)
            SCCfillID(i, tvs, s);
    SCC gr = transpose();
    for (int i = 0; i < V; i++)
        tvs[i] = false;
    while (s.empty() == false) {
        int v = s.top();
        s.pop();
        if (tvs[v] == false) {
            gr.SSCDFS(v, tvs, v, arr);
            int min = v;
            for (int i = 0; i < n; i++) {
                if (arr[i] == v) {
                    if (min > i)
                        min = i;
                }
            }
            for (int i = 0; i < n; i++)
                if (arr[i] == v)
                    arr[i] = min;
        }
    }
}

int main() {
    int n, e;
    cin >> n;
    cin >> e;
    SCC g(n);
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        g.connect(u, w);
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = n + 2;
    }
    g.printSCCs(n, arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}