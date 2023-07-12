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

int n, a[N], x;

int32_t main() {
#define TASKNAME "1090"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> x;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int lo = 0;
	int res = 0;
	for(int hi = n - 1; hi >= lo; hi--) {
		if(a[hi] + a[lo] <= x)
			lo++;
		res++;
	}
	cout << res;
	return 0;
}
/*
INPUT
4 10
7 2 3 9
OUTPUT
3
*/
