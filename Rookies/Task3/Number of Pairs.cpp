#include <bits/stdc++.h>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define endd "\n"
#define ll long long
#define all(x) (x).begin(), (x).end()
using namespace std;

int main()
{
    FAST;
    int t;
    cin >> t;
    while (t--)
    {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        sort(all(a));

        ll pairs = 0;
        for (int i = 0; i < n; i++)
        {
            int x = l - a[i], y = r - a[i];
            auto min = lower_bound(a.begin() , a.end(), x);
            auto max = upper_bound(a.begin() , a.end(), y);

            pairs += distance(min, max);
        }

        cout << pairs << endl;
    }
}