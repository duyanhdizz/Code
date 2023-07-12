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
const int N = 9 + 5e3;
const int INF = 1e9;

int n, x, a[N];
map<int, int> m;

int32_t main() {
#define TASKNAME "1641"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> x;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int z = j + 1; z <= n; z++) {
				if(m.count(x - a[i] - a[j] - a[z])) {
					return cout << m[x - a[i] - a[j] - a[z]] << ' ' << i << ' ' << j << ' ' << z << '\n', 0;
				}
			}
		}
		m[a[i]] = i;
	}
	cout << "IMPOSSIBLE";
	return 0;
}
/*
INPUT
4 8
2 7 5 1
OUTPUT
*/
