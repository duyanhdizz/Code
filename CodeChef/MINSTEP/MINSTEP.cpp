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
	int res1 = 0, res2 = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if(x == 1) res1++;
		else res2++;
	}
	if(res1 == res2) cout << 0 << '\n';
	else {
		if(res1 % 2 != res2 % 2) cout << -1 << '\n';
		else cout << abs(res1 - res2) / 2 << '\n';
	}
}

int32_t main() {
#define TASKNAME "MINSTEP"
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
4
6
1 1 1 -1 -1 -1
5
-1 -1 1 1 1
4
1 1 1 1
8
-1 -1 -1 1 -1 1 1 -1
OUTPUT
0
-1
2
1
*/
