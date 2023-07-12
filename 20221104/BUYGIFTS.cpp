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
const int N = 9 + 1e5;
const int INF = 1e9;

int n, m, a[N];

int32_t main() {
#define TASKNAME "BUYGIFTS"
    ios_base::sync_with_stdio (0);
    cin.tie (0);
    if ( fopen( TASKNAME".inp", "r" ) ) {
        freopen (TASKNAME".inp", "r", stdin);
        freopen (TASKNAME".out", "w", stdout);
    }
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int res = INF;
    for(int i = 0; i + m - 1 < n; i++) res = min(res, a[i + m - 1] - a[i]);
    cout << res;
    return 0;
}

/*
INPUT
6 4
10 12 10 5 7 22
OUTPUT
5
*/