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
    int n, d;
    cin >> n >> d;
    vector<int> a(n);  
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int i=0,j=2;
    ll s=0;
    while (i<n)
    {
        while(j<n&&a[j]-a[i]<=d){
           
           j++;
        }
        ll c= j-i-1; 
        if (c >= 2) { 
           s += 1LL*c*(c-1)/2; 
        }
        i++;
    }
    
    
    cout<<s<<endl;
    
}