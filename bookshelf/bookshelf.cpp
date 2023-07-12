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

int n, l;

bool cmp(pii l, pii r) {
	if(l.se < r.se) return true;
	else return false;
}

int32_t main() {
#define TASKNAME "bookshelf"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> l;
	vector<pair<int, int>> v(n);
	for(int i = 0; i < n; i++) cin >> v[i].fi >> v[i].se;
	sort(all(v), cmp);
	int sum = 0, res = 0, ans = 0, i = 0;
	while(i < n) {
		if(sum + v[i].se > l) {
			ans += res;
			sum = v[i].se;
			res = v[i].fi;
			//cout << i;
		} else {
			sum += v[i].se;
			res = max(res, v[i].fi);
		}
		i++;
		//cout << ans << '\n';
	}
	cout << ans + res;
	return 0;
}
/*
INPUT
5 10
5 7
9 2
8 5
13 2
3 8
OUTPUT
21
*/
