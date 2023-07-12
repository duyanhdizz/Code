#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int seg[N], add[N];

void update(int k, int l, int r, int u, int v, int value) {
    if(l > r || v < l || u > r) return;
    if(u <= l && r <= v) {
        seg[k] += value;
        add[k] += value;
        return;
    }
    update(k*2, l, (l+r)/2, u, v, value);
    update(k*2+1, (l+r)/2+1, r, u, v, value);
    seg[k] = max(seg[k*2], seg[k*2+1]) + add[k];
}

int getmax(int k, int l, int r, int u, int v) {
    if(l > r || v < l || u > r) return INT_MIN;
    if(u <= l && r <= v) return seg[k];
    return max(getmax(k*2, l, (l+r)/2, u, v), getmax(k*2+1, (l+r)/2+1, r, u, v)) + add[k];
}

void YeuHuong() {
    int n, m;
    cin >> n >> m;
    FOR(i, 1, m) {
        int u, v, k;
        cin >> u >> v >> k;
        update(1, 1, n, u, v, k);
    }
    int q;
    cin >> q;
    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << getmax(1, 1, n, u, v) << '\n';
    }
}

int32_t main() {
#define TASKNAME "qmax"
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    cout.tie (nullptr);
    int tbegin = clock();
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    YeuHuong();
    cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
    return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
