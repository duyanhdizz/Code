#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

ll k, a;

bool check(ll n) {
	if (n <= a) {
		ll x = n * (n + 1) / 2;
		if (k >= x) return true;
		if (k + n - 1 >= x) return true;
		return false;
	}
	ll x = (n + 1) * n / 2;
	ll y =  n - a;
	y = y * (a + n - 1) / 2;
	return (x + y <= k || x + y - a + 1 <= k);
}
ll times(ll save, ll a) {
	if(save < a) {
		ll x = save * (save + 1) / 2;
		ll ans = save;
		if (x < k) {
			ll p = k - x;
			p = (p + save - 1) / save;
			ans += p;
		}
		return ans;
	}
	ll ans = save + save - a;
	ll x = (save + 1) * save / 2;
	ll y =  save - a ;
	y = y * (a + save - 1) / 2;
	if (x + y < k) {
		ll p = k - x - y;
		p = (p + save - 1) / save;
		ans += p;
	}
	return ans;
}

void YeuHuong() {
	cin >> a;
	ll lo = 1, hi = k, DA = a;
	while (lo <= hi) {
		ll mid = (lo + hi) >> 1;
		if(check(mid)) {
			DA = mid;
			lo = mid + 1;
		} else hi = mid - 1;
	}
	cout << times(DA, a) << '\n';
}

int32_t main() {
#define TASKNAME "SPEEDTEST"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase;
	cin >> k >> testcase;
	while(testcase--)
		YeuHuong();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
