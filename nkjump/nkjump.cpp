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
const int N = 2106;
const int INF = 2106 + 1e9;

int a[N];
gp_hash_table<int, int> g[N];
int _ = 1;

void solve(int x, int o) {
	if(g[x].size() == 0) {
		_ = max(_, o);
		return;
	}
	each(y, g[x]) {
		solve(y.fi, o + 1);
	}
}

void SaKaTa() {
	int n;
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	sort(a + 1, a + n + 1);
	FOR(i, 3, n) {
		FOR(j, 1, i - 1) {
			int _ = a[i] - a[j];
			if(binary_search(a + 1, a + 1 + n, _)) {
				g[_][a[i]]++;
				g[a[j]][a[i]]++;
			}
		}
	}
	FOR(i, 1, n) {
		if(g[i].size() != 0) {
			solve(i, 1);
		}
	}
	cout << _;
}

int32_t main() {
#define TASKNAME "nkjump"
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
