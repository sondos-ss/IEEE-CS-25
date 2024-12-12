#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};



int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char d[] = {'U', 'D', 'L', 'R'};
 
 
bool is(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    int x0 = -1, y0 = -1; 
    vector<pair<int, int>> monsters; 
    
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'A') {
                x0 = i;
                y0 = j;
            }
            else if (grid[i][j] == 'M') {
                monsters.push_back({i, j});
            }
        }
    }
    
    
    vector<vector<int>> time(n, vector<int>(m, -1));
    queue<pair<int, int>> qq;
    
    for (auto& monster : monsters) {
        int x = monster.first, y = monster.second;
        qq.push({x, y});
        time[x][y] = 0;
    }
    
 
    while (!qq.empty()) {
        int x, y;
        tie(x, y) = qq.front();
        qq.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is(nx, ny, n, m) && grid[nx][ny] != '#' && time[nx][ny] == -1) {
                time[nx][ny] = time[x][y] + 1;
                qq.push({nx, ny});
            }
        }
    }
    
    vector<vector<int>> dist(n, vector<int>(m, -1));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    
    q.push({x0, y0});
    dist[x0][y0] = 0;
    
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i], ny = y + dy[i];
            if (is(nx, ny, n, m) && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                if (time[nx][ny] == -1 || dist[x][y] + 1 < time[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + 1;
                    parent[nx][ny] = {x, y};
                    q.push({nx, ny});
 
                    if (nx == 0 || ny == 0 || nx == n-1 || ny == m-1) {
                        
                        vector<char> path;
                        while (nx != x0 || ny != y0) {
                            int px = parent[nx][ny].first;
                            int py = parent[nx][ny].second;
                            if (nx - px == -1) path.push_back('D');
                            if (nx - px == 1) path.push_back('U');
                            if (ny - py == -1) path.push_back('R');
                            if (ny - py == 1) path.push_back('L');
                            nx = px;
                            ny = py;
                        }
                        reverse(path.begin(), path.end());
                        
                        cout << "YES" << endl;
                        cout << path.size() << endl;
                        for (char c : path) cout << c;
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "NO" << endl;
    
}