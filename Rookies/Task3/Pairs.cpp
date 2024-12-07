#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    FAST;
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(all(a));
    ll pairs = 0;
    int l = 0, r = 0;

    while (l < n) {
        while (r < n && a[r] < a[l] + t) {
            r++;
        }

        if (r < n && a[r] == a[l] + t) {
            int count = 0;
            while (r < n && a[r] == a[l] + t) {
                count++;
                r++;
            }
            pairs += count;
        }
        l++;
    }

    cout << pairs << endl;
}
