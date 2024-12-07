#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define ll long long
using namespace std;

int main() {
    FAST;
    int n;
    cin >> n;
    vector<int> t(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    int l = 0, r = n - 1;
    ll t1 = 0, t2 = 0;
    int a = 0, b = 0;

    while (l <= r) {
        if (t1 <= t2) {
            t1 += t[l];
            l++;
            a++;
        } else {
            t2 += t[r];
            r--;
            b++;
        }
    }
    cout << a << " " << b << endl;
}