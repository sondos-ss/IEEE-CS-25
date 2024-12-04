#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define ld long double
const double pi = 3.1415926535897;
#define all(x) (x).begin(), (x).end()
using namespace std;


int main() {
    FAST;
    int n,q;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(all(a));
    cin>>q;
    while(q--){
        int m;
        cin>>m;
        int c = upper_bound(a.begin(), a.end(), m) - a.begin(); 
        cout<<c<<endl;
    }

}