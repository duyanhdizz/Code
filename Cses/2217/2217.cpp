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

int n, t, a[N];

int32_t main() {
#define TASKNAME "2217"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> t;
	int d[n];
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		d[a[i]] = i;
	}
	while(t--) {
		int l, r;
		cin >> l >> r;
		swap(a[l], a[r]);
		for(int i = 1; i <= n; i++) {
			//cin >> a[i];
			d[a[i]] = i;
		}
		int res = 1;
		for(int i = 2; i <= n; i++)
			if(d[i] < d[i - 1]) res++;
		cout << res << '\n';
		fill(d, d + n, 0);
		//swap(d[a[l]], d[a[r]]);
	}
	return 0;
}
/*
INPUT
5 3
4 2 1 5 3
2 3
1 5
2 3
OUTPUT
2
3
4
*/
