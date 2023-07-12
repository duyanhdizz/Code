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

int n, a[N];
bool d[N], dd[N];

int32_t main() {
#define TASKNAME "COUTSUM"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int res = 0;
	fill(d, d + N, false);
	fill(dd, dd + N, false);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		d[2 * a[i]] = true;
		if(d[a[i]] == true) res++;
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			dd[a[i] + a[j]] = true;
		}
	}
	for(int i = 0; i < n; i++)
		if(dd[a[i]] == true) res++;
	cout << res;
	return 0;
}
/*
INPUT
3
1 2 3
OUTPUT
2
*/
