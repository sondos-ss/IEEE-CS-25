#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endd "\n"
#define ll long long
#define ld long double
const double pi = 3.1415926535897;
#define all(x) (x).begin(), (x).end()
using namespace std;

bool is(int num) {
    while (num > 0) {
        int d = num % 10;
        if (d != 4 && d != 7)
            return false;
        num /= 10;
    }
    return true;
}


int main() {
    FAST;
    int num;
    cin>>num;
    vector<int> nums;
    for (int i = 4; i <= 1000; i++) {
        if (is(i))
            nums.push_back(i);
    }

    for (int i = 0; i <nums.size();i++) {
        if (num %nums[i] == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    

}