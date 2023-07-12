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
#define ll unsigned long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

ll n;

inline uint64_t mod_mult64(uint64_t a, uint64_t b, uint64_t m) {
	return __int128_t(a) * b % m;
}
uint64_t mod_pow64(uint64_t a, uint64_t b, uint64_t m) {
	uint64_t ret = (m > 1);
	for (;;) {
		if (b & 1) ret = mod_mult64(ret, a, m);
		if (!(b >>= 1)) return ret;
		a = mod_mult64(a, a, m);
	}
}

// Works for all primes p < 2^64
bool is_prime(uint64_t n) {
	if (n <= 3) return (n >= 2);
	static const uint64_t small[] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
		71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
		149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
	};
	for (size_t i = 0; i < sizeof(small) / sizeof(uint64_t); ++i) {
		if (n % small[i] == 0) return n == small[i];
	}

	// Makes use of the known bounds for Miller-Rabin pseudoprimes.
	static const uint64_t millerrabin[] = {
		2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
	};
	static const uint64_t A014233[] = {  // From OEIS.
		2047LL, 1373653LL, 25326001LL, 3215031751LL, 2152302898747LL,
		3474749660383LL, 341550071728321LL, 341550071728321LL,
		3825123056546413051LL, 3825123056546413051LL, 3825123056546413051LL, 0,
	};
	uint64_t s = n-1, r = 0;
	while (s % 2 == 0) {
		s /= 2;
		r++;
	}
	for (size_t i = 0, j; i < sizeof(millerrabin) / sizeof(uint64_t); i++) {
		uint64_t md = mod_pow64(millerrabin[i], s, n);
		if (md != 1) {
			for (j = 1; j < r; j++) {
				if (md == n-1) break;
				md = mod_mult64(md, md, n);
			}
			if (md != n-1) return false;
		}
		if (n < A014233[i]) return true;
	}
	return true;
}

int32_t main() {
#define TASKNAME "PFACTOR"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	vector<ll> ans;
	FOR(i, 1, sqrt(n)) {
		if(n % i == 0) {
			if(is_prime(i)) ans.pb(i);
			if(i * i != n && is_prime(n / i)) ans.pb(n / i);
		}
	}
	sort(all(ans));
	cout << ans[ans.size() - 1];
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
5144819348555
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
