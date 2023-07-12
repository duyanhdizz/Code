#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e5;
const int INF = 1e9;

int n, k, a[N];

int32_t main() {
#define TASKNAME "sumk"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i - 1];
    int res = -INF;
    for(int i = 1; i + k - 1 <= n; i++) res = max(res, a[i + k - 1] - a[i - 1]);
    cout << res;
    return 0;
}
/*
INPUT
6 2 
2 4 5 2 9 1
OUTPUT
11
*/
