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
const int NM = 9 + 1e6;
const int INF = 1e9;

int n, x, a[N][N], p[NM];

int32_t main() {
#define TASKNAME "luckyseq"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> x;
	for(int i = 1; i <= n; i++) cin >> p[i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = p[i] + p[j];
	int res = 0;
	for(int i = 1; i <= n; i++) {
		int j = 0, z = 0;
		while(j < n && z < n) {
			int tt = 0;
			for(int k = j; k < j + i; k++) {
				for(int kk = z; kk < z + i; kk++) {
					tt += a[k][kk];
				}
			}
			if(tt == x) res++;
			j++;
			z++;
		}
	}
	cout << res;
	return 0;
}
/*
INPUT
4 90
5 5 5 5
OUTPUT
4
*/
