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

vector<int> prime, pref;
vector<int> lpf;
void sieve(int n) {
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);

	for (int x = 3; x <= n; x += 2) {
		if (lpf[x] == 2) prime.push_back(lpf[x] = x);
		for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i)
			lpf[prime[i] * x] = prime[i];
	}

	pref.assign(prime.size(), 0);
	pref[0] = prime[0];
	for (int i = 1; i < prime.size(); i++) {
		pref[i] = pref[i - 1] + prime[i];
	}
}

void IU() {
	int l, r, val;
	cin >> l >> r >> val;
	auto pos_min_l = lower_bound(all(prime), l) - prime.begin();
	auto pos_max_l = upper_bound(all(prime), val) - prime.begin() - 1;
	auto pos_min_r = upper_bound(all(prime), val) - prime.begin();
	auto pos_max_r = upper_bound(all(prime), r) - prime.begin() - 1;
	cout << pos_min_r;
	cout << (pos_max_l - pos_min_l + 1) * val - (pref[pos_max_l] - pref[pos_min_l - 1]) + (pref[pos_max_r] - pref[pos_min_r - 1]) - (pos_max_r - pos_min_r + 1) * val << '\n';
}

int32_t main() {
#define TASKNAME "PRIME"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sieve(1e6);
	int testcase;
	cin >> testcase;
	while(testcase--)
		IU();
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
