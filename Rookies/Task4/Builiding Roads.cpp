#include <bits/stdc++.h>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
const int MAX = 200000;
using namespace std;

void bfs(int x, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& c) {
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        c.push_back(node);
        for (int i : adj[node]) {
            if (!visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n + 1);  
    vector<bool> visited(n + 1, false); 

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    vector<vector<int>> v;  
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> c;
            bfs(i, adj, visited, c);
            v.push_back(c);
        }
    }
    
   
    int road = v.size() - 1;
    cout << road << endl;
    
   
    for (int i = 1; i < v.size(); ++i) {
        cout << v[0][0] << " " << v[i][0] << endl;
    }
    
    
}