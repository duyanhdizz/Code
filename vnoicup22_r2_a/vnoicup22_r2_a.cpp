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
const int N = 9 + 1e5;
const int INF = 1e9;

int a[N], b[N];
map<pair<int, int>, int> _;

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	vector<pii> v(n);
	int pos = 0;
	each(x, v) {
		cin >> x.fi >> x.se;
		_[ {x.fi, x.se}] = ++pos;
	}
	sort(all(v));
	FOR(i, 0, n - 1) {
		a[i] = v[i].fi;
		b[i] = v[i].se;
	}
	FOR(i, 0, n - 2) {
		int pos = upper_bound(a, a + n, b[i]) - a;
		if(pos == n) continue;
		cout << "YES" << '\n';
		cout << _[ {a[i], b[i]}] << ' ' << _[ {a[pos], b[pos]}];
		return;
	}
	cout << "NO";
}

int32_t main() {
#define TASKNAME "vnoicup22_r2_a"
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
