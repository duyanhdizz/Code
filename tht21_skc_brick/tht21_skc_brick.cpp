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
const int N = 2106 + 1e6;
const int INF = 2106 + 1e9;

vector<int> prime;
vector<int> lpf;
void sieve(int n) {
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);
	for (int x = 3; x <= n; x += 2) {
		if (lpf[x] == 2) prime.push_back(lpf[x] = x);
		for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i)
			lpf[prime[i] * x] = prime[i];
	}
}

void SaKaTa() {
	sieve(1e6);
	vector<ll> multi(prime.size() - 1);
	for (int i = 0; i < multi.size(); ++i)
		multi[i] = 1LL * prime[i] * prime[i + 1];
	int q;
	cin >> q;
	while (q--) {
		ll n;
		cin >> n;
		cout << n-*--upper_bound(all(multi), n) << "\n";
	}
}

int32_t main() {
#define TASKNAME "tht21_skc_brick"
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
		SaKaTa();
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
