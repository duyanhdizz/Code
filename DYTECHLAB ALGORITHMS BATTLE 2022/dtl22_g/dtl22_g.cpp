#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int32_t main() {
#define TASKNAME "dtl22_g"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int 
	int len = cnt3 * 3 / 2;
	int t = len / 3;
	int l = len + 1, r = n - len - 1;
	for (int i = 1; i <= t; i++) {
		groups3.push_back(vector<int> {i, i + t, n - 2 * i - t});
		groups3.push_back(vector<int> {n - i, n - (len - 2 * i + 1), len - i + 1});
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7 3
2 2 2
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3 4
2 5
1 6
------------------------------    |
==================================+
*/
