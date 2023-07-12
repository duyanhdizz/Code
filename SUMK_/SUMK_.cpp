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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, k, ans = 0, a[N];
unordered_map<int, int> m, m_;

void SaKaTa() {
	cin >> n >> k;
	FOR(i, 1, n) cin >> a[i];
	m.clear();
	m_.clear();
	vector<int> v, c;
	v.pb(0);
	FOR(j, 1, n / 2) {
		c.clear();
		each(x, v) {
			c.pb(x + a[j]);
//			cout << x << '\n';
		}
		each(x, c) v.pb(x);
	}
	each(x, v) {
		if(x != 0 && x < k) m[x]++;
		if(x == k) ans++;
	}
	v.clear();
	v.pb(0);
	FOR(j, n / 2 + 1, n) {
        c.clear();
		each(x, v) {
			c.pb(x + a[j]);
//			cout << x << '\n';
		}
		each(x, c) v.pb(x);
	}
	each(x, v) {
		if(x != 0 && x < k) ans += m[k - x];
		if(x == k) ans++;
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "SUMK_"
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
