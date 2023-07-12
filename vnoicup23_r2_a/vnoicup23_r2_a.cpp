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
const int N = 9 + 5e2;
const int INF = 1e9;

char dp[N][N];

void SaKaTa() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			cin >> dp[i][j];
		}
	}
	FOR(i, 0, n + 1) dp[i][m + 1] = 'a', dp[i][0] = 'a';
	FOR(i, 0, m + 1) dp[n + 1][i] = 'a', dp[n + 1][0] = 'a';
	FOR(i, 1, n) {
		FOR(j, 1, m) {
			if(dp[i][j] != dp[i + 1][j] && dp[i][j] != dp[i][j + 1] && dp[i + 1][j] != dp[i + 1][j + 1] && dp[i][j + 1] == dp[i + 1][j + 1] && dp[i][j] != 'a' && dp[i + 1][j] != 'a' && dp[i][j + 1] != 'a' && dp[i + 1][j + 1] != 'a') {
				cout << "YES";
				return;
			}
		}
	}
	cout << "NO";
}

int32_t main() {
#define TASKNAME "vnoicup23_r2_a"
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
