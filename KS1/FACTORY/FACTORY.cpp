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
const int N = 9 + 6e3;
const int INF = 1e9;

struct Task {
	int t1, t2, t3;
};

int f[N][N];
Task a[N];

void SaKaTa() {
	int n;
	cin >> n;
	FOR(i, 1, n) {
		cin >> a[i].t1 >> a[i].t2 >> a[i].t3;
	}
	f[0][0] = 0;
	FOR(i, 1, n) {
		FOR(j, 1, n) {
			f[i][j] = INF;
			f[i][j] = min({f[i - 1][j] + a[i].t2, f[i - 1][j - a[i].t2], f[i - 1][j - a[i].t3] + a[i].t3});
		}
	}
	FOR(i, 1, n) cout << f[n][i] << ' ';
}

int32_t main() {
#define TASKNAME "FACTORY"
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
5
2 1 0
0 5 0
2 4 1
0 0 3
2 1 1
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
