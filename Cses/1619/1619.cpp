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

int n;

int32_t main() {
#define TASKNAME "1619"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<pii> v(2 * n);
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		v[2 * i] = {x, 1};
		v[2 * i + 1] = {y, -1};
	}
	sort(all(v));
	int res = 0, ans = 1;
	for(auto i : v) res += i.se, ans = max(ans, res);
	cout << ans;
	return 0;
}
/*
INPUT
3
5 8
2 4
3 9
OUTPUT
2
*/
