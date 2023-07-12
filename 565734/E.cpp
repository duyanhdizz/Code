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
const int N = 2106 - (2008 - 50);
const int INF = 2106 + 1e9;

int h, w, __ = 1;
char a[N][N];
bool vis[N][N];

int drow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dcol[8] = { 0, 1, 1, 1, 0, -1, -1, -1};

void dfs(int i, int j, int _) {
//	if((a[i][j] + 1) == a[i + 1][j] && vis[i + 1][j] == false && i + 1 >= 0 && i + 1 < h && j >= 0 && j < w) {
//		__ = max(__, _ + 1);
//		vis[i + 1][j] = true;
//		dfs(i + 1, j, _ + 1);
//	}
//	if((a[i][j] + 1) == a[i + 1][j - 1] && vis[i + 1][j - 1] == false && i + 1 >= 0 && i + 1 < h && j - 1 >= 0 && j - 1 < w) {
//		__ = max(__, _ + 1);
//		vis[i + 1][j - 1] = true;
//		dfs(i + 1, j - 1, _ + 1);
//	}
//	if((a[i][j] + 1) == a[i + 1][j + 1] && vis[i + 1][j + 1] == false && i + 1 >= 0 && i + 1 < h && j + 1 >= 0 && j + 1 < w) {
//		__ = max(__, _ + 1);
//		vis[i + 1][j + 1] = true;
//		dfs(i + 1, j + 1, _ + 1);
//	}
//	if((a[i][j] + 1) == a[i - 1][j] && vis[i - 1][j] == false && i - 1 >= 0 && i - 1 < h && j >= 0 && j < w) {
//		__ = max(__, _ + 1);
//		vis[i - 1][j] = true;
//		dfs(i - 1, j, _ + 1);
//	}
//	if((a[i][j] + 1) == a[i - 1][j + 1] && vis[i - 1][j + 1] == false && i - 1 >= 0 && i - 1 < h && j + 1 >= 0 && j + 1 < w) {
//		__ = max(__, _ + 1);
//		vis[i - 1][j + 1] = true;
//		dfs(i - 1, j + 1, _ + 1);
//	}
//	if((a[i][j] + 1) == a[i - 1][j - 1] && vis[i - 1][j - 1] == false && i - 1 >= 0 && i - 1 < h && j - 1 >= 0 && j - 1 < w) {
//		__ = max(__, _ + 1);
//		vis[i - 1][j - 1] = true;
//		dfs(i - 1, j - 1, _ + 1);
//	}
//	if((a[i][j] + 1) == a[i][j + 1] && vis[i][j + 1] == false && i >= 0 && i < h && j + 1 >= 0 && j + 1 < w) {
//		__ = max(__, _ + 1);
//		vis[i][j + 1] = true;
//		dfs(i, j + 1, _ + 1);
//	}
//	if((a[i][j] + 1) == a[i][j - 1] && vis[i][j - 1] == false && i >= 0 && i < h && j - 1 >= 0 && j - 1 < w) {
//		__ = max(__, _ + 1);
//		vis[i][j - 1] = true;
//		dfs(i, j - 1, _ + 1);
//	}
	FOR(___, 0, 7) {
		int r = i + drow[___];
		int c = j + dcol[___];
		if (r >= 0 && r < h && c >= 0 && c < w && vis[r][c] == false && a[r][c] == a[i][j] + 1) {
			vis[r][c] = true;
			dfs(r, c, _ + 1);
		}
	}
	__ = max(_, __);
}

void SaKaTa() {
	int tc = 0;
	while(cin >> h >> w) {
		if(h == 0 && w == 0) break;
		__ = 0;
		FOR(i, 0, h - 1) {
			FOR(j, 0, w - 1) {
				cin >> a[i][j];
			}
		}
		memset(vis, false, sizeof vis);
		FOR(i, 0, h - 1) {
			FOR(j, 0, w - 1) {
				if(a[i][j] == 'A') {
					vis[i][j] = true;
					dfs(i, j, 1);
				}
			}
		}
		cout << "Case " << ++tc << ": " << __ << '\n';
	}
}

int32_t main() {
#define TASKNAME "E"
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
4 3
ABE
CFG
BDH
ABC
0 0
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
Case 1: 4
------------------------------    |
==================================+
*/
