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

vector<pii> v;

void build() {
	v.pb({0, 6});
	v.pb({1, 2});
	v.pb({2, 5});
	v.pb({3, 5});
	v.pb({4, 4});
	v.pb({5, 5});
	v.pb({6, 6});
	v.pb({7, 3});
	v.pb({8, 7});
	v.pb({9, 6});
}

int solve(int n) {
	int res = 0;
	while(n > 0) {
		res += v[n % 10].se;
		n /= 10;
	}
	return res;
}

void SaKaTa() {
	int a, b;
	cin >> a >> b;
	int ans = 0;
	FOR(i, a, b) {
		ans += solve(i);
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "DIGCLOCK"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	build();
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
