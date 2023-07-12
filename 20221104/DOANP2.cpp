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
const int N = 9 + 1e6;
const int INF = 1e9;

int n;

int32_t main() {
#define TASKNAME "DOANP2"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].fi >> v[i].se;
	sort(all(v));
	int res = 0;
	int dau = v[0].fi, cuoi = v[0].se;
	for(int i = 1; i < n; i++)
		if(v[i].fi <= cuoi) cuoi = max(cuoi, v[i].se);
		else res += cuoi - dau, dau = v[i].fi, cuoi = v[i].se;
	res += (cuoi - dau);
	cout << res;
	return 0;
}
/*
INPUT
3
-5 10
0 6
-100 10
OUTPUT
21
*/
