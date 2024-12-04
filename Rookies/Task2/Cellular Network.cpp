#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define ld long double
#define LSB(x) (__builtin_ffsll(x) - 1)
#define MSB(x) (64 - __builtin_clzll(x) - 1)
const double pi = 3.1415926535897;
const int MAX_c = 1073741824;
#define all(x) (x).begin(), (x).end()
using namespace std;

int main() {
    FAST;
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    int c=0,t=0,r=0;
    for(int i=0;i<n;i++){
        while(t<m-1&&abs(a[i]-b[t+1])<=abs(a[i]-b[t])){
            t++;
        }
        r=max(r,abs(a[i]-b[t]));
    }

    cout<<r<<endl;
}