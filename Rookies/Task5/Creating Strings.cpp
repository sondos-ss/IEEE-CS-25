#include <bits/stdc++.h>
#define FAST                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
using namespace std;

void f(string &str, int idx, set<string> &a) {
    if (idx == str.size()) {
        a.insert(str);
        return;
    }
    for (int i = idx; i < str.size(); i++) {
        swap(str[idx], str[i]); 
        f(str, idx + 1, a); 
        swap(str[idx], str[i]); 
    }
}

int main() {
    string s;
    cin >> s;

    set<string> a;
    f(s, 0, a);

    
    cout << a.size() << endl;
    for (const string &i : a) {
        cout << i << endl;
    }

    
}