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

const int DA = 1e5 + 9;

vector<int> f[N], g[N];

void IU() {
	int n, m;
	cin >> n >> m;
	FOR(i, 1, n) {
		int x, y;
		cin >> x >> y;
		x += DA;
		y += DA;
		f[x].pb(y);
		g[y].pb(x);
	}
	FOR(i, 1, 4e5) {
		if(f[i].size() != 0) sort(all(f[i]));
		if(g[i].size() != 0) sort(all(g[i]));
	}
	int left = DA, right = DA;
	while(m--) {
		char c;
		cin >> c;
		if(c == 'L' || c == 'R') {
			if(c == 'R') {
				int lo = 0, hi = g[right].size() - 1;
				while(lo < hi) {
					int mid = lo + hi >> 1;
					if(g[right][mid] <= left) {
						lo = mid + 1;
					} else {
						hi = mid;
					}
				}
				left = g[right][lo];
			} else {
				int lo = 0, hi = g[right].size() - 1;
				while(lo < hi) {
					int mid = lo + hi >> 1;
					if(g[right][mid] < left) {
						lo = mid + 1;
					} else {
						hi = mid;
					}
				}
				if(g[right][lo] == left) lo--;
				left = g[right][lo];
			}
		} else {
			if(c == 'U') {
				int lo = 0, hi = f[left].size() - 1;
				while(lo < hi) {
					int mid = lo + hi >> 1;
					if(f[left][mid] <= right) {
						lo = mid + 1;
					} else {
						hi = mid;
					}
				}
				right = f[left][lo];
			} else {
				int lo = 0, hi = f[left].size() - 1;
				while(lo < hi) {
					int mid = lo + hi >> 1;
					if(f[left][mid] < right) {
						lo = mid + 1;
					} else {
						hi = mid;
					}
				}
				if(f[left][lo] == right) lo--;
				right = f[left][lo];
			}
		}
	}
	cout << left - DA << ' ' << right - DA;
}

int32_t main() {
#define TASKNAME "ANT"
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
10 6
0 0
1 1
2 1
0 2
-1 2
-1 3
2 3
2 4
4 3
2 -1
ULURDL
---
7 5
0 0
0 1
0 -1
1 0
1 -1
3 0
3 -1
DRRUD
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1 1
---
3 -1
------------------------------    |
==================================+
*/
