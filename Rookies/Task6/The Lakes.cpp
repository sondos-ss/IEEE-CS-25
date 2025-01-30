#include <bits/stdc++.h>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define endd "\n"
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).e()
const int MAX = 200000;
using namespace std;

const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int main() {
    int t;
    cin >> t; 
    while (t--) {
        int n, m;
        cin >> n >> m; 
        vector<vector<int>> a(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j]; 
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        int ans = 0; 

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] > 0 && !visited[i][j]) {
                    int volume = 0;
                    stack<pair<int, int>> s;
                    s.push({i, j});
                    while (!s.empty()) {
                        int x=s.top().first,y=s.top().second;
                        s.pop();
                        if (x < 0 || x >= n || y < 0 || y >= m || a[x][y] == 0 || visited[x][y]) {
                            continue;
                        }
                        visited[x][y] = true;
                        volume += a[x][y];
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k];
                            int ny = y + dy[k];
                            s.push({nx, ny});
                        }
                    }
                    if (volume > ans) {
                        ans = volume;
                    }
                }
            }
        }

        cout << ans << endl; 
    }

    
}