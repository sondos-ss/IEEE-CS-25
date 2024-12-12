#include <bits/stdc++.h>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
using namespace std;
 
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char d[] = {'U', 'D', 'L', 'R'};

bool is(int x, int y, int n, int m, const vector<string>& grid) {
    return x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#';
}
 
int main() {
    int n, m;
    cin >> n >> m;
 
    vector<string> grid(n);
    int x0=0, y0=0, xn=0, yn=0;
 
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                x0 = i;
                y0 = j;
            } else if (grid[i][j] == 'B') {
                xn = i;
                yn = j;
            }
        }
    }
 
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<int>> previous(n, vector<int>(m, -1));  
    q.push({x0, y0});
    visited[x0][y0] = true;
 
    while (!q.empty()) {
        pair<int, int> c = q.front();
        q.pop();
 
        if (c.first == xn && c.second == yn) {
            cout << "YES" << endl;
            
            
            vector<char> path;
            while (c.first != x0 || c.second != y0) {
                int dir = previous[c.first][c.second];
                path.push_back(d[dir]);
                c.first -= dx[dir];
                c.second -= dy[dir];
            }
            reverse(path.begin(), path.end());
            
            cout << path.size() << endl;
            for (char ch : path) {
                cout << ch;
            }
            cout << endl;
            return 0;
        }
 
        for (int i = 0; i < 4; ++i) {
            int x = c.first + dx[i];
            int y = c.second + dy[i];
 
            if (is(x, y, n, m, grid) && !visited[x][y]) {
                visited[x][y] = true;
                previous[x][y] = i; 
                q.push({x, y});
            }
        }
    }
 
    cout << "NO" << endl;
}
