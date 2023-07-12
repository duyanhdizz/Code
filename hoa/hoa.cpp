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

int32_t main() {
#define TASKNAME "hoa"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	int res = 0;
	for(int i = 0; i < n - (1 - n % 2); i++) {
		res += (a[i] - (1 - a[i] % 2));
	}
	cout << res;
	return 0;
}
/*
INPUT
4
4 6 9 1
OUTPUT
17
*/
