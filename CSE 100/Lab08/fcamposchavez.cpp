#include <iostream>
#include <vector>
#include <climits>

using namespace std;

string buildMat(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        return "A" + to_string(i);
    }
    else {
        return "(" + buildMat(s, i, s[i][j]) + buildMat(s, s[i][j] + 1, j) + ")";
    }
}

void matChain(const vector<int>& d) {
    int n = d.size() - 1;
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i < n - len + 1; i++) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {
                int cost = m[i][k] + m[k + 1][j] + d[i] * d[k + 1] * d[j + 1];
                if (cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << m[0][n - 1] << endl;

    string matSequence = buildMat(s, 0, n - 1);
    cout << matSequence << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> dimensions(n + 1);

    for (int i = 0; i <= n; i++) {
        cin >> dimensions[i];
    }

    matChain(dimensions);

    return 0;
}

