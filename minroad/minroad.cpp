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
const int N = 9 + 1e6;
const int INF = 1e9;

void SaKaTa() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<pii> tree (n);
	each(x, tree) cin >> x.fi >> x.se;
	sort(all(tree));
	vector<int> pos1(n), pos2(n);
	int x = 0, y = 0, res = INF;
	FOR(i, 0, n - 1) {
		if(tree[i].se == 1) {
			pos1[x++] = tree[i].fi;
		} else {
			pos2[y++] = tree[i].fi;
		}
		if(x >= a && y >= b) {
			res = min(res, tree[i].fi - min(pos1[x - a], pos2[y - b]));
		}
	}
	cout << (res == INF ? -1 : res);
}

int32_t main() {
#define TASKNAME ""
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
