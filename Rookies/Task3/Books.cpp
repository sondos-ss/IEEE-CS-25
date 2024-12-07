#include <bits/stdc++.h>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define all(x) (x).begin(), (x).end()
using namespace std;

int main()
{
    FAST;
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 0, r = 0;
    int ans = 0; int s = 0;
    while (r < n)
    {
        if (s + a[r] <= t)
        {
            s += a[r];
            r++;
            ans = max(ans, r - l);
        }
        else
        {
            s -= a[l];
            l++;
        }
    }
    cout << ans << endl;
}