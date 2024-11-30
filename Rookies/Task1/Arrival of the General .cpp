#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define ld long double
const double pi = 3.1415926535897;
using namespace std;

int main(){
   int n;
   cin>>n;
   vector<int>a(n);

   for (int i = 0; i < n; i++)
   {
        cin>>a[i];
   }

   int t = a[0], ti = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] > t) {
            t = a[i];
            ti = i;
        }
    }

    
    int s = a[0], si = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] <= s) {
            s = a[i];
            si = i;
        }
    }

    
    int c = ti;
    c += (n-si-1);

    if (ti > si) {
        c -= 1;
    }
    cout << c << endl;
   
}