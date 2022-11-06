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

//TLE 4 / 10

void solve() {
	int n;
	cin >> n;
	int res = 0;
	for(int y = n + 1; y <= n * n + n; y++) {
		if((n * n) % (y - n) == 0) {
			res++;
		}
	}
	cout << res << '\n';
}

int32_t main() {
#define TASKNAME "xyn_sub1"
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
2
2
3
OUTPUT
3
3
*/
