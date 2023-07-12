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
const int N = 9 + 1e7;
const int INF = 1e9;

int n;
map<int, int> pre;

int solve(int nn) {
	int res = 1;
	int i = 2;
	while(nn > 1 && i <= sqrt(nn)) {
		if(nn % i == 0) {
			res *= i;
			while(nn % i == 0) nn /= i;
		}
		i++;
	}
	res *= nn;
	return res;
}

int32_t main() {
#define TASKNAME "icpc21_national_l"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	ll res = 0;
	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		res += pre[solve(x)];
		pre[solve(x)]++;
	}
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
6
1 2 3 4 5 6
------------------------------
4
7 7 7 7
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1
------------------------------
6
------------------------------    |
==================================+
*/
