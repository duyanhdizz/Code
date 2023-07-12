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
const int N = 9 + 1e6;
const int INF = 1e9;

int n, a[N];

int32_t main() {
#define TASKNAME "1643"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int ans = -INF;
	for(int i = 0; i < n; i++) cin >> a[i], ans = max(ans, a[i]);
	ll res = 0, res2 = 0, res3 = 0;
	for(int i = 0; i < n; i++) {
		res = max(res3, res + a[i]);
		res2 = max(res2, res);
	}
   	if(res2 > 0) cout << res2;
   	else cout << ans;
	return 0;
}
/*
INPUT
8
-1 3 -2 5 3 -5 2 2
OUTPUT
9
*/
