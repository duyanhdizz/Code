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
const int N = 9 + 50;
const int INF = 1e9;

int n;
char a[N][N];

int DA() {
	int H = 0;
	REP(i, 0, n) {
		REP(j, 0, n) {
			int c1 = 0, c2 = 0, x = i, y = j;
			while(x < n && a[x][j] == a[i][j]) x++, c1++;
			while(y < n && a[i][y] == a[i][j]) y++, c2++;
			H = max({H, c1, c2});
		}
	}
	return H;
}

void IU() {
	cin >> n;
	REP(i, 0, n) {
		REP(j, 0, n) {
			cin >> a[i][j];
		}
	}
	int ans = 0;
	REP(i, 0, n) {
		REP(j, 0, n) {
			if(i + 1 < n && a[i][j] != a[i + 1][j]) {
				swap(a[i][j], a[i + 1][j]);
				ans = max(ans, DA());
				swap(a[i][j], a[i + 1][j]);
			}
			if(j + 1 < n && a[i][j] != a[i][j + 1]) {
				swap(a[i][j], a[i][j + 1]);
				ans = max(ans, DA());
				swap(a[i][j], a[i][j + 1]);
			}
		}
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "CANDY"
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
		IU();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3
CCP
CCP
PPC
---
5
YCPZY
CYZZP
CCPPP
YCYZC
CPPZZ
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
---
4
------------------------------    |
==================================+
*/
