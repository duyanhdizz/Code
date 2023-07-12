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
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

ll solvecot(int m, int n) {
	ll lo = 1, hi = n;
	while (lo + 1 < hi) {
		ll mid = (lo + hi + 1) >> 1;
		ll s1 = (((1ll * m * (m - 1)) / 2) * n * 1ll + m) * (mid - 1) + 1ll * m * (mid - 1) * (mid - 2) / 2;
		ll s2 = (m * n + 1) * m * n * 1ll / 2 - s1;
		if (s1 == s2) return mid;
		else if (s1 < s2) lo = mid;
		else hi = mid;
	}
	if (lo < hi) {
		ll s1 = (((1ll * m * (m - 1)) / 2) * n * 1ll + m) * (lo - 1) + 1ll * m * (lo - 1) * (lo - 2) / 2;
		ll s2 = (1ll * m * n + 1) * m * n * 1ll / 2 - s1;
		ll s11 = (((1ll * m * (m - 1)) / 2) * n * 1ll + m) * (hi - 1) + 1ll * m * (hi - 1) * (hi - 2) / 2;
		ll s22 = (1ll * m * n + 1) * m * n * 1ll / 2 - s11;
		return (abs(s1 - s2) <= abs(s11 - s22) ? lo : hi );
	}
	return lo;
}

ll solvehang(int m, int n) {
	ll lo = 1, hi = m;
	while (lo + 1 < hi) {
		ll mid = (lo + hi + 1) >> 1;
		ll s1 = ((mid - 1) * n * 1ll + 1) * (1ll * n * (mid - 1)) / 2;
		ll s2 = (1ll * m * n + 1) * m * n * 1ll / 2 - s1;
		if (s1 == s2) return mid;
		else if (s1 < s2) lo = mid;
		else hi = mid;
	}
	if (lo < hi) {
		ll s1 = ((lo - 1) * n * 1ll + 1) * (1ll * n * (lo - 1)) / 2;
		ll s2 = (m * n * 1ll + 1) * 1ll * m * n / 2 - s1;
		ll s11 = ((hi - 1) * n * 1ll + 1) * (1ll * n * (hi - 1)) / 2;
		ll s22 = (m * n * 1ll + 1) * 1ll * m * n / 2 - s11;
		return (abs(s1 - s2) <= abs(s11 - s22) ? lo : hi );
	}
	return lo;
}

void YeuHuong() {
	int m, n;
	cin >> m >> n;
	ll cot = solvecot(m, n), hang = solvehang(m, n);
	ll s1 = (((1ll * m * (m - 1)) / 2) * n * 1ll + m) * (cot - 1) + 1ll * m * (cot - 1) * (cot - 2) / 2;
	ll s2 = (1ll * m * n + 1) * 1ll * m * n / 2 - s1;
	ll s11 = ((hang - 1) * n * 1ll + 1) * (1ll * n * (hang - 1)) / 2;
	ll s22 = (1ll * m * n + 1) * m * n * 1ll /2 - s11;
	(abs(s1 - s2) <= abs(s11 - s22)) ? cout << "V " << cot : cout << "H " << hang;
	cout << '\n';
}

int32_t main() {
#define TASKNAME "TABCUT"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase;
	cin >> testcase;
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
