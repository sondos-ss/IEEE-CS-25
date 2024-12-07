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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(all(a));
    int f = 0, r = n - 1;
    int ans = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        while (a[i] - a[f] > 5)
        {
            f++;
        }

        ans = max(ans, i - f + 1);
    }
    cout << ans << endl;
}