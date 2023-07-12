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
const int N = 9 + 1e3;
const int INF = 1e9;

int n, m, t;
bool dp[N][N];
int check[N][N], sum[N][N];

int32_t main() {
#define TASKNAME "FLIP"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m >> t;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			char x;
			cin >> x;
			if(x == '*') dp[i][j] = true;
			else dp[i][j] = false;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			check[i][j] = dp[i + 1][j] + dp[i][j + 1] + dp[i][j] + dp[i + 1][j + 1];
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			if(check[i][j] % 2 == 1) sum[i][j]++;
		}
	}
	while(t--) {
		int x, y, u, v;
		cin >> x >> y >> u >> v;
		u--;
		v--;
		int che = sum[u][v] - sum[u][y - 1] - sum[x - 1][v] + sum[x - 1][y - 1];
		if(che == 0) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}
/*
INPUT
4 5 3
*.*..
.*.*.
**.*.
*.*.*
2 2 4 5
2 1 3 4
1 4 1 5
OUTPUT
YES
NO
YES
*/
