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

int find(int x, vector<int> &lab) {
  if(lab[x] == x) return x;
  return lab[x] = find(lab[x], lab);
}

int32_t main() {
#define TASKNAME "fc143_pause"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	vector<int> a(n), ans(n + 1), p(n);
	for(int &x : a) cin >> x;
	for(int &x : p) cin >> x, --x;
	vector<int> app(n), lab(n);
	vector<long long> sum(n);
	for(int i = 0; i < n; ++i) {
		lab[i] = i;
	}
	for(int i = n - 1; i >= 0; --i) {
		int id = p[i];
		if(id + 1 < n && app[id + 1]) {
			lab[id] = find(id + 1, lab);
		}
		if(id > 0 && app[id - 1]) {
			sum[find(id - 1, lab)] += sum[find(id, lab)];
			lab[find(id, lab)] = find(id - 1, lab);
		}
		sum[find(id, lab)] += a[id];
		ans[i] = sum[find(id, lab)];
		if(i + 1 < n) ans[i] = max(ans[i], ans[i + 1]);
		app[id] = 1;
	}
	for(int i = 1; i <= n; ++i) cout << ans[i] << endl;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
1 3 2 5
3 4 1 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
5
4
3
0
------------------------------    |
==================================+
*/
