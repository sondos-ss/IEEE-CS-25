#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};



void bfs(int x, int y, int n, int m, vector<vector<char>>& g, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int X = x + dx[i];
            int Y = y + dy[i];
            if (X >= 0 && X < n && Y >= 0 && Y < m && g[X][Y] == '.' && !visited[X][Y]) {
                visited[X][Y] = true;
                q.push({X, Y});
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int ans = 0;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '.' && !visited[i][j]) {
                bfs(i, j, n, m, g, visited);
                ans++;
            }
        }
    }

    cout << ans << endl;

   
}