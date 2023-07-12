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

int n, m;

int32_t main() {
#define TASKNAME "MILK"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	vector<pii> v(m);
	for(int i = 0; i < m; i++) cin >> v[i].fi >> v[i].se;
	sort(all(v));
	int ans = 0, i = 0;
	while(n > 0 && i < m) {
		if(n >= v[i].se) ans += v[i].fi * v[i].se, n -= (v[i].se), i++;
		else {
			int solitcan = v[i].se - n;
			ans += solitcan * v[i].fi;
			break;
		}
	}
	cout << ans;
	return 0;
}
/*
INPUT
100 5
5 20
9 40
3 10
8 80
6 30
OUTPUT
630
*/
