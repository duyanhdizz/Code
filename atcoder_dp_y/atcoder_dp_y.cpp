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
const int N = 9 + 3e3;
const int INF = 1e9;

int f[N][N];
map<char, char> a[N];

const int mod = 1e9 + 7;

void YeuHuong() {
	int h, w;
	cin >> h >> w;
	FOR(i, 1, h) {
		FOR(j, 1, w) {
			a[i][j] = '.';
		}
	}
	int test;
	cin >> test;
	while(test--) {
		int n, m;
		cin >> n >> m;
		a[n][m] = '#';
	}
	f[0][1] = 1;
	FOR(i, 1, h) {
		FOR(j, 1, w) {
			if(a[i][j] == '#') f[i][j] = 0;
			else f[i][j] = (f[i - 1][j] + f[i][j - 1]) % mod;
		}
	}
	cout << f[h][w];
}

int32_t main() {
#define TASKNAME "atcoder_dp_y"
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

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
