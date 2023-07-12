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

int n, a[N];
bool ans[N];
vector<pii> v;

bool check(int x, int y) {
	int lo = 0, hi = v.size() - 1;
	//int res = INF;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(v[mid].fi > x || (v[mid].fi == x && v[mid].se > y)) {
			hi = mid - 1;
		} else if(v[mid].fi < x) lo = mid + 1;
		else return true;
	}
	return false;
}

int32_t main() {
#define TASKNAME "cvp_sxtk16"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		ans[i] = false;
	}
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			v.pb({a[i] + a[j], j});
		}
	}
	sort(all(v));
	int res = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(ans[i] == false && check(3 * a[i] - a[j], j - 1)) {
				res++;
				ans[i] = true;
			}
		}
	}
	cout << res;
	return 0;
}
/*
INPUT
3
1
2
3
OUTPUT
1
*/
