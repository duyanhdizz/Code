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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int n, m, res;

const int mod = 1e9 + 7;

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

void YeuHuong() {
	cin >> n >> m;
	res = 0;
	if(m > n) {
		res = (n % mod) * ((m - n) % mod);
		res %= mod;
		m = n;
	}
	while (1 <= m) m = find(1, m, n / m) - 1;
	cout << res;
}

int32_t main() {
#define TASKNAME "Sum of Remainders"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
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
