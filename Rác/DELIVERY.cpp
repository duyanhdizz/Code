#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<int> x, int m) {
    sort(x.begin(), x.end(), greater<int>());

    ll ans = 0;
    for(int i = 0; i < x.size(); i += m) {
        ans += x[i] * 2;
    }
    return ans;
} 

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> x1(n), x2(n);
    for(int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x < 0) x1.push_back(-x);
        else x2.push_back(x);
    }

    ll ans = solve(x1, m) + solve(x2, m);
    cout << ans;

    return 0;
}
