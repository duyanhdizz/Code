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
	int n, x;
	cin >> n >> x;
	set<int> s;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s.insert(x);
	}
	cout << min(n - x, (int)s.size()) << '\n';
}

int32_t main() {
#define TASKNAME "CM164364"
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
3
2 1
1 2
4 2
1 1 1 1
5 3
50 50 50 100 100
OUTPUT
1
1
2
*/
