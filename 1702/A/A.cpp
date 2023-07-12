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

int n;

int32_t main() {
#define TASKNAME ""
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		int c = to_string(m).size();
		int d = stoi("1" + string(c - 1, '0'));
		cout << m - d << '\n';
	}
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7
1
2
178
20
999999999
9000
987654321
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
0
1
78
10
899999999
8000
887654321
------------------------------    |
==================================+
*/
