#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define sz(a) a.size()
#define all(a) a.begin(),a.end()
const int N = 1 + 2e5;
const int INF = 1e18;

int n, t;

struct SegmentTree {
    int n;
    int t[N];
    void build(const vector<int>& a) {
        n = a.size();
        copy(a.begin(), a.end(), t + n);
        for (int i = n - 1; i > 0; --i) t[i] = max(t[i << 1], t[i << 1 | 1]);
    }
    void modify(int u, int val) {
        for (t[u += n] = val; u > 1; u >>= 1) t[u >> 1] = max(t[u], t[u ^ 1]);
    }
    int query(int l, int r) {
        int res = -INF;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) res = max(res, t[l++]);
            if (r & 1) res = max(res, t[--r]);
        }
        return res;
    }
} tree;

void solve() {
    int x, y, z, MOD;
    cin >> x >> y >> z;
    if(x == 0) tree.modify(y - 1, z);
    else cin >> MOD, cout << tree.query(y - 1, z) % MOD << '\n';
}

int32_t main() {
#define TASKNAME ""
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    tree.build(a);
    cin >> t;
    while(t--)
        solve();
    return 0;
}
