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

int two(int x) {
	return x * x;
}

void YeuHuong() {
	int n;
	cin >> n;
	vector<pii> v(n);
	each(x, v) cin >> x.fi >> x.se;
	int DA = -INF;
	REP(i, 0, n - 1) {
		REP(j, i + 1, n) {
			DA = max(DA, two(v[j].fi - v[i].fi) + two(v[j].se - v[i].se));
		}
	}
	cout << DA;
}

int32_t main() {
#define TASKNAME "MAX"
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
		YeuHuong();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
0 0
0 1
1 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
------------------------------    |
==================================+
*/
