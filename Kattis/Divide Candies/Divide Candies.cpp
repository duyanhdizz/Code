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

int n, m;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	ll res = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= m; j++) {
			if((i * i + j * j) % m == 0) {
				int hang = (n / m);
				if(n % m >= i) hang++;
				int cot = (n / m);
				if(n % m >= j) cot++;
				res += 1ll * hang * cot;
			}
		}
	}
	cout << res;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
3 3
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1
------------------------------    |
==================================+
*/
