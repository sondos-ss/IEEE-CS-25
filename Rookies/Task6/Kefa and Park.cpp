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
void f(int node, int p, const vector<vector<int>>& a, const vector<int>& v, int cat, int m, int& ans) {
    
    if (v[node] == 1) {
        cat++;
    } else {
        cat = 0;
    }
    if (cat > m) {
        return;
    }
    bool is = true;
    for (int i : a[node]) {
        if (i != p) {
            is = false;
            f(i, node, a, v, cat, m, ans);
        }
    }
    if (is && cat <= m) {
        ans++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<vector<int>> a(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }

    int ans = 0;
    f(1, -1, a, v, 0, m, ans);

    cout << ans << endl;

    
}