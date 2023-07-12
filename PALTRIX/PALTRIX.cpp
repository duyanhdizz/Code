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

int n, m, a[N][N];
map<int, int> m_m;

int solve(int a, int b, int c, int d) {
	int solg = 1;
	if(b != a) solg++;
	if(c != a && c != b) solg++;
	if(d != c && d != b && d != a) solg++;
	if(solg == 1) return 0;
	if(solg == 4) return 3;
	if(solg == 3) return 2;
	if(solg == 2) {
		m_m.clear();
		m_m[a]++;
		m_m[b]++;
		m_m[c]++;
		m_m[d]++;
		if(m_m[a] == 3 || m_m[b] == 3 || m_m[c] == 3 || m_m[d] == 3) return 1;
		else return 2;
	}
}

int32_t main() {
#define TASKNAME "PALTRIX"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> m >> n;
	FOR(i, 1, m) {
		FOR(j, 1, n) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	FOR(i, 1, m / 2) {
		FOR(j, 1, n / 2) {
			ans += solve(a[i][j], a[m - i + 1][j], a[i][n - j + 1], a[m - i + 1][n - j + 1]);
		}
	}
	if(m & 1) {
		int p = m / 2;
		p++;
		FOR(i, 1, n / 2)
		if(a[p][i] != a[p][n - i + 1]) ans++;
	}
	if(n & 1) {
		int p = n / 2;
		p++;
		FOR(i, 1, m / 2)
		if(a[i][p] != a[m - i + 1][p]) ans++;
	}
	cout << ans;
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
