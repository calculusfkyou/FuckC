#include "bits/stdc++.h"

using namespace std;
vector<string> graph(110);
int n, m;
int dRow[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dColumn[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dfs(int row, int column) {
    if (row < 0 || row >= n || column < 0 || column >= m)
        return 0;
    if (graph[row][column] == '*')
        return 0;
    graph[row][column] = '*';
    for (int d = 0; d < 8; d++)
        dfs(row + dRow[d], column + dColumn[d]);
    return 1;
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0)
            break;
        for (int i = 0; i < n; i++)
            cin >> graph[i];
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (graph[i][j] == '@') {
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}