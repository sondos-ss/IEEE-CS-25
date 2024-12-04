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

bool f(ll mid , int k ,int n){
    ll sum = 0;
    ll p=1;
    while (mid/p>0) {
        sum += mid / p;
        if (sum >= n) return true;
        p *= k;
    }
    return sum >= n;
}

int main() {
    FAST;
    int n, k;
    cin >> n >> k;
    
    ll l=1,r=1e9;
    int c=0;
    int ans=-1;
    
    while (l<=r)
    {
        ll mid=(l+r)/2;
        if(f(mid,k,n)){
            ans=mid;
            r=mid-1;
            
        }
        else{
            l=mid+1;
        }
        
    }
    cout<<ans<<endl;
    
    
}