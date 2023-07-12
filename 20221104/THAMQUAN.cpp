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
const int N = 9 + 1e3;
const int INF = 1e9;

int n, m, a[N], b[N];
map<int, int> d;
vector<pii> v;

int32_t main() {
#define TASKNAME "THAMQUAN"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
	sort(a, a + n, greater<int>());
	for(int i = 0; i < m; i++) {
		int x;
		cin >> x;
		v.pb({x, i + 1});
	}
	sort(all(v));
	int res = 0;
	for(int i = 0; i < n; i++) res += a[i] * v[i].fi, d[a[i]] = v[i].se;
	cout << res << '\n';
	for(int i = 0; i < n; i++) cout << d[b[i]] << '\n';
	return 0;
}
/*
INPUT
3 4
7 5 9
17 13 15 10
OUTPUT
256
2
3
4
*/
