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
const int INF = 1e9;

const int MOD = 1e9 + 7;

char m[N][N];
int f[N][N];

void SaKaTa() {
	int n;
	cin >> n;
	FOR(i, 0, n - 1) {
		FOR(j, 0, n - 1) {
			cin >> m[i][j];
		}
	}
	if (m[0][0] == '.') {
		f[0][0] = 1;
	} else {
		f[0][0] = 0;
	}
	FOR(i, 1, n - 1) {
		if (m[i][0] == '.') {
			f[i][0] = f[i - 1][0];
		} else {
			f[i][0] = 0;
		}
		if (m[0][i] == '.') {
			f[0][i] = f[0][i - 1];
		} else {
			f[0][i] = 0;
		}
	}
	FOR(i, 1, n - 1) {
		FOR(j, 1, n - 1) {
			if (m[i][j] == '*') {
				f[i][j] = 0;
			} else {
				f[i][j] = (f[i - 1][j] + f[i][j - 1]) % MOD;
			}
		}
	}
	cout << f[n - 1][n - 1];
}

int32_t main() {
#define TASKNAME "GRIDPATH"
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
