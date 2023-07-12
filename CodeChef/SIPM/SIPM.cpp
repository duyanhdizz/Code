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

int t;

void solve() {
	int n;
	cin >> n;
	map<int, int> d;
	ll res = 0, res2 = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		d[x]++;
		if(d[x] == 1) {
			if(x > 0) res += x;
			else res2 += x;
		}
	}
	cout << res << ' ' << res2 << '\n';
}

int32_t main() {
#define TASKNAME "SIPM"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
INPUT
OUTPUT
*/