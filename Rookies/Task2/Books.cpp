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
    int n, t;
    cin >> n >> t;
    vector<int> a(n);  
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l=0,r=0;
    int c=0;
    int s=0;
    while(r<n){
      if(s+a[r]<=t){
          s+=a[r];
          r++;
          c=max(c,r-l);
      }
      else{
        s-=a[l];
        l++;
        
      }
      
      
    }
    cout<<c<<endl;
    
}