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
   string s;
   cin>>s;
   vector<int>a(n);

   for (int i = 0; i < n; i++)
   {
        cin>>a[i];
   }
   int ans=INT_MAX,b=0;
   for (int i = 0; i < n-1; i++)
   {
        if(s[i]=='R'&&s[i+1]=='L'){
            b=1;
            int d=(a[i+1]-a[i])/2;
            ans=min(ans,d);

        }
   }
   if(b==0)ans=-1;
   cout<<ans<<endl;
   

   
}