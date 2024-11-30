#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>e(n);
    for(int i=0;i<n;i++){
        cin>>e[i];
    }
    int p=0;
    int c=0;
     for (int i = 0; i < n; i++) {
        if (e[i] == -1) {
            if (p>0) {
                p--;
            } 
            else {
                c++;
            }
        } 
        else {
            p+=e[i];
        }
    }
    cout<<c;

}