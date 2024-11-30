#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define ld long double
const double pi = 3.1415926535897;
using namespace std;

int main(){
   string d,s;
   cin>>d>>s;
   string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./";
   string message = "";
   for(int i=0;i<s.length();i++){
    char c=s[i];
    int p=keyboard.find(s[i]);
    if(d=="L"){
        message+=keyboard[p+1];
    }
    else{
      message+=keyboard[p-1];
    }
   }
   cout<<message;
}