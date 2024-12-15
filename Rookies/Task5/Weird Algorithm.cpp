#include <bits/stdc++.h>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define endd "\n"
#define ll long long
#define ld long double
#define all(x) (x).begin(), (x).end()
const int MAX = 200000;
using namespace std;

void f(ll n){
    cout<<n<<" ";
    if(n==1)return;
    if (n&1)
        f(3*n+1);
        
    else
        f(n/2); 
    
}

 
int main() {
    FAST;

    ll n;
    cin>>n;
    f(n);
}
