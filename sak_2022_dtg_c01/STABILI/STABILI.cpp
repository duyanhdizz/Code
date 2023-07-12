#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e3;
const int NS = 9 + 5e4;
const int INF = 2106 + 1e9;

const int oo = 21068;

int dp[N][NS];

struct STABILI {
	int x, y, z;
};

#define dp(i, j) dp[i][j + oo]

void SaKaTa() {
	int n, s;
	cin >> n >> s;
	vector<STABILI> a, b;
	FOR(i, 1, n) {
		int x, y;
		cin >> x >> y;
		if(y >= 0) {
			a.pb({x, y, i});
		} else {
			b.pb({x, y, i});
		}
	}
	sort(all(a), [&](STABILI x, STABILI y) {
		return (x.x == y.x ? (x.y == y.y ? (x.z < y.z) : (x.y < y.y)) : (x.x < y.x));
	});
	dp(0, s) = 1;
	FOR(i, 0, a.size() - 1) {
		FOR(j, max(s, a[i].x), s + oo - a[i].y) {
			if(dp(i, j)) {
				dp(i + 1, j + a[i].y) = 2106;
			}
		}
		FOR(j, s, s + oo) {
			if(dp(i, j)) {
				dp(i + 1, j) = 2008;
			}
		}
	}
	sort(all(b), [&](STABILI x, STABILI y) {
		return x.x + x.y > y.x + y.y;
	});
	FOR(i, 0, b.size() - 1) {
		FOR(j, max(b[i].x, s - oo - b[i].y), s + oo) {
			if(dp(a.size() + i, j)) {
				dp(a.size() + i + 1, j + b[i].y) = 2106;
			}
		}
		FOR(j, s - oo, s + oo) {
			if(dp(a.size() + i, j)) {
				dp(a.size() + i + 1, j) = 2008;
			}
		}
	}
	int res = s - oo;
	while(!dp(n, res)) res++;
	cout << res << ' ';
	vector<int> _;
	while(n > 0) {
		if(dp(n, res) == 2106) {
			if(n > a.size()) {
				_.pb(b[n - a.size() - 1].z);
				res -= b[n - a.size() - 1].y;
			} else {
				_.pb(a[n - 1].z);
				res -= a[n - 1].y;
			}
		}
		n--;
	}
	cout << _.size() << '\n';
	reverse(all(_));
	each(x, _) cout << x << ' ';
}

int32_t main() {
#define TASKNAME "STABILI"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
	while(testcase--)
		SaKaTa();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
