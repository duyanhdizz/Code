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
const int N = 9 + 2e3;
const int INF = 1e9;

int n, f[N][N];
string ans, s;

void solve(int i, int j, int L, int R) {
	if (L > R) return;
	if (i == j) ans[L] = s[i];
	else {
		if (s[i] == s[j]) {
			ans[L] = ans[R] = s[i];
			solve(i + 1, j - 1, L + 1, R - 1);
		} else {
			if (f[i][j] == f[i + 1][j])
				solve(i + 1, j, L, R);
			else
				solve(i, j - 1, L, R);
		}
	}
}

void SaKaTa() {
	getline(cin, s);
	n = s.size() - 1;
	FORD(i, n, 0) {
		FOR(j, i, n) {
			if (i == j) f[i][j] = 1;
			else {
				if (s[i] == s[j]) {
					if (i == j - 1) f[i][j] = 2;
					else f[i][j] = f[i + 1][j - 1] + 2;
				} else f[i][j] = max(f[i + 1][j], f[i][j - 1]);
			}
		}
	}
	ans.resize(f[0][n]);
	solve(0, n, 0, f[0][n] - 1);
	cout << ans;
}

int32_t main() {
#define TASKNAME "nkpalin"
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
