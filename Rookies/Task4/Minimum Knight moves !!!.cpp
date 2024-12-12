#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;

const vector<pair<int, int>> d = {
    {2, 1}, {1, 2}, {-1, 2}, {-2, 1},
    {-2, -1}, {-1, -2}, {1, -2}, {2, -1}
};


bool is(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}

int main() {
    int t;
    cin >> t;
    

    while (t--) {
        string a, b;
        cin >> a >> b;

        if (a == b) {
            cout << 0 << endl; 
            continue;
        }

        pair<int, int> start = {a[0]-'a',a[1]-'1'}, end = {b[0]-'a',b[1]-'1'};

        queue<pair<int, int>> q;
        vector<vector<bool>> visited(8, vector<bool>(8, false));

        q.push(start);
        visited[start.first][start.second] = true;

        int moves = 0;
        bool found = false;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [x, y] = q.front();
                q.pop();
                for (auto [dx, dy] : d) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx == end.first && ny == end.second) {
                        cout << moves + 1 << endl;
                        found = true;
                        break;
                    }

                    if (is(nx, ny) && !visited[nx][ny]) {
                        visited[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }

                if (found) break;
            }

            if (found) break;
            moves++;
        }

        if (!found) {
            cout << -1 << endl;
        }
    }

   
}