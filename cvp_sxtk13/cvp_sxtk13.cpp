#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 5e5;
const int INF = 1e9;

int n, h, a[N];

int32_t main() {
#define TASKNAME "cvp_sxtk13"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> h;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if(i % 2 != 0) {
            a[1]++;
            a[x + 1]--;
        } else a[h - x + 1]++;
    }
    int res = a[1];
    for(int i = 2; i <= h; i++) {
        a[i] += a[i - 1];
        res = min(res, a[i]);
    }
    int res2 = 0;
    for(int i = 1; i <= h; i++)
        if(res == a[i])
            res2++;
    cout << res << ' ' << res2;
    return 0;
}
/*
INPUT
14 5
1
3
4
2
2
4
3
4
3
3
3
2
3
3
OUTPUT
7 2
*/
