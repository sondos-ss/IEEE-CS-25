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

void f(const vector<array<int, 3>> &v, const vector<array<int, 4>> &a, vector<bool> &used, int &ans) {
    bool is = true;

    for (int i = 1; i <= 100; i++) {
        int p = 0;
        for (int j = 0; j < a.size(); j++) {
            if (!used[j]) continue;
            auto &[s, e, power, cost] = a[j];
            if (s <= i && i <= e) {
                p += power;
            }
        }

        int r = 0;
        for (int j = 0; j < v.size(); j++) {
            auto &[s, e, requirement] = v[j];
            if (s <= i && i <= e) {
                r = requirement;
                break;
            }
        }

        if (p < r) {
            is = false;
            break;
        }
    }

    if (is) {
        int cost = 0;
        for (int i = 0; i < a.size(); i++) {
            if (used[i]) {
                cost += a[i][3];
            }
        }
        ans = min(ans, cost);
    }
}

void cond(int idx, const vector<array<int, 3>> &v, const vector<array<int, 4>> &a, vector<bool> &used, int &ans) {
    if (idx == a.size()) {
        f(v, a, used, ans);
    } else {
        used[idx] = false;
        cond(idx + 1, v, a, used, ans);
        used[idx] = true;
        cond(idx + 1, v, a, used, ans);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<array<int, 3>> v;
    vector<array<int, 4>> a;
    vector<bool> used(m, false);
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        int s, e, requirement;
        cin >> s >> e >> requirement;
        v.push_back({s, e, requirement});
    }

    for (int i = 0; i < m; i++) {
        int s, e, power, cost;
        cin >> s >> e >> power >> cost;
        a.push_back({s, e, power, cost});
    }

    cond(0, v, a, used, ans);

    cout << ans << endl;
}
