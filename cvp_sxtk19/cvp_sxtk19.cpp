#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e18;

int n, a[N];

int32_t main() {
#define TASKNAME "cvp_sxtk19"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int res = 0;
	for(int i = 1; i <= n; i++) cin >> a[i], res += a[i];
	sort(a + 1, a + n + 1);
	for(int i = n; i >= 1; i--) if(res / i >= a[i]) return cout << n - i, 0;
	return 0;
}
/*
INPUT
5
1 2 3 4 5
OUTPUT
2
*/
