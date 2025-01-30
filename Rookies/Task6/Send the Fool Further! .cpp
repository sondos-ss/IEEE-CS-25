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

int ans = 0;

void f(vector<vector<pair<int, int>>>& a,int u, int p, int c) {
    ans = max(ans, c);
    for (auto& edge : a[u]) {
        int v = edge.first;
        int cost = edge.second;
        if (v != p) {
            f(a,v, u, c + cost);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> a(n); 
    for (int i = 0; i < n - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].push_back({v, c});
        a[v].push_back({u, c});
    }

    f(a , 0, -1, 0);

    cout << ans << endl;

   
}