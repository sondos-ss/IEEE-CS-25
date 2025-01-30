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

void f(int i, vector<vector<int>>& a, vector<bool>& visited) {
    visited[i] = true;
    for (int v : a[i]) {
        if (!visited[v]) {
            f(v, a, visited);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> p(n + 1); 
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<vector<int>> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        a[i].push_back(p[i]);
        a[p[i]].push_back(i);
    }
    vector<bool> visited(n + 1, false);
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            f(i, a, visited);
            ans++;
        }
    }

    cout << ans << endl;

    
}