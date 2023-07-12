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

int n, q, a[N];

int32_t main() {
#define TASKNAME "UPDATE"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> q;
	fill(a, a + n + 9, 0);
	while(q--) {
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		a[l]++;
		a[r + 1]--;
	}
	for(int i = 1; i < n; i++) a[i] += a[i - 1];
	for(int i = 0; i < n; i++) cout << a[i] << ' ';
	return 0;
}
/*
INPUT
5 2
1 4
4 5
OUTPUT
1 1 1 2 1
*/
