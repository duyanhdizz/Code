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

int n, m, d[N];

int32_t main() {
#define TASKNAME "COUNTNUM"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	fill(d, d + N, 0);
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		d[x]++;
	}
	while(m--) {
		int x;
		cin >> x;
		cout << d[x] << '\n';
	}
	return 0;
}
/*
INPUT
3 2
1 2 3
3
4
OUTPUT
1
0
*/
