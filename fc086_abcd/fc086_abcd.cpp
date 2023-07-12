#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 4e3;
const int INF = 1e9;

int n, a[N];
vector<int> cnt;

struct qhash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x)
	const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

gp_hash_table<ll, pair<ll, ll>, qhash> m;

int32_t main() {
#define TASKNAME "fc086_abcd"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			m[a[i] + a[j]] = {i, j};
	int res = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++) {
			int ans = a[j] - a[i];
			//auto pos = binary(all(cnt), ans) - cnt.begin();
			//cout << cnt[pos] << '\n';
			if(m.find(ans) != m.end() && m[ans].fi != i && m[ans].se != j) res = max(res, a[j]);
			//cout << ans << '\n';
		}
	if(res != 0) cout << res;
	else cout << "no solution";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
4
1
2
3
6
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
6
------------------------------    |
==================================+
*/
