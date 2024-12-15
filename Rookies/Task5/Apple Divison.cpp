#include <bits/stdc++.h>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define ll long long
using namespace std;

ll f(vector<ll>&a,ll i,ll s1,ll s2,ll n){
    if(i==n){
        return abs(s1-s2);
    }
    ll d1 = f(a,i+1, s1 + a[i], s2,n);
    ll d2 = f(a,i+1, s1, s2 + a[i],n);
    return min(d1, d2);
    
}

 
int main() {
    FAST;

    ll n;
    cin>>n;
    vector<ll>a(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    cout<<f(a,0,0,0,n);
}
