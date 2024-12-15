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

const int n = 8;
int ans = 0;
 
bool is(int row, int col, vector<string>& b) {
    for (int i = 0; i < row; i++) {
        if (b[i][col] == 'Q')
            return false;
    }
 
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (b[i][j] == 'Q')
            return false;
    }
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (b[i][j] == 'Q')
            return false;
    }
 
    return true;
}
 
void f(int row, vector<string>& b) {
    if (row == n) {
        ans++;
        return;
    }
 
    for (int col = 0; col < n; col++) {
        if (b[row][col] == '.' && is(row, col, b)) {
            b[row][col] = 'Q';
            f(row+1, b);
            b[row][col] = '.'; 
        }
    }
}
 
int main() {
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
 
    f(0, b);
    cout << ans << endl;
 
    
}