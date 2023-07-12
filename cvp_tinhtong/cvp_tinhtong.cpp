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
const int INF = 1e9;
const int mod = 1e9 + 7;

int n, m, res;

int find(int x, int y, int t) {
	int ans = n, st = x,en = y;
	while(st <= en) {
		int mid = (st + en) / 2;
		if (n / mid > t) st = mid + 1;
		else {
			en = mid - 1;
			ans = min(mid, ans);
		}
	}
	int d = y - ans + 1;
	st = n % y, en = n % ans;
	en += st;
	if (en % 2 == 0) en /= 2;
	else d /= 2;
	res += (en % mod) * (d % mod);
	res %= mod;
	return ans;
}

int32_t main() {
#define TASKNAME "cvp_tinhtong"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> m;
	res = 0;
	if(m > n) {
		res = (n % mod) * ((m - n) % mod);
		res %= mod;
		m = n;
	}
	while (1 <= m) m = find(1, m, n / m) - 1;
	//cout << res;
	return 0;
}
