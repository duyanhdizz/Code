#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e7;
const int INF = 1e9;

int t;

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

vector<unsigned long long> pre;
bool prime[N];

void sang() {
	fill(prime, prime + N, true);
	prime[0] = prime[1] = false;
	for (unsigned long long i = 2; i <= N; i++) {
		if (prime[i] == true) {
			pre.pb(i);
			for (unsigned long long j = 2 * i; j <= N; j += i) {
				prime[j] = false;
			}
		}
	}
}

vector<unsigned long long> candidates;

const unsigned long long MAX_VAL = 10000000000000000000ULL;

void init() {
	for(unsigned long long start_id = 0; start_id < pre.size(); start_id++) {
	    if(prime[start_id] > 2154434) break;
		unsigned long long prod = 1ULL;
		for(unsigned long long end_id = start_id; end_id < pre.size(); end_id++) {
			if(prod > MAX_VAL / pre[end_id]) break;
			prod *= prime[end_id];
			candidates.pb(prod);
		}
	}
	sort(all(candidates));
}

pair<unsigned long long, unsigned long long> factor(unsigned long long n) {
	unsigned long long s = 0;
	while ((n & 1) == 0) {
		s++;
		n >>= 1;
	}
	return {s, n};
}

unsigned long long pow(unsigned long long a, unsigned long long d, unsigned long long n) {
	unsigned long long result = 1;
	a = a % n;
	while (d > 0ULL) {
		if (d & 1ULL) result = result * a % n;
		d >>= 1ULL;
		a = a * a % n;
	}
	return result;
}

bool test_a(unsigned long long s, unsigned long long d, unsigned long long n, unsigned long long a) {
	if (n == a) return true;
	unsigned long long p = pow(a, d, n);
	if (p == 1) return true;
	for (; s > 0; s--) {
		if (p == n-1) return true;
		p = p * p % n;
	}
	return false;
}

bool miller(unsigned long long n) {
	if (n < 2) return false;
	if ((n & 1) == 0) return n == 2;
	unsigned long long s, d;
	tie(s, d) = factor(n-1);
	return test_a(s, d, n, 2) && test_a(s, d, n, 3) && test_a(s, d, n, 5) && test_a(s, d, n, 7) && test_a(s, d, n, 11) && test_a(s, d, n, 13) && test_a(s, d, n, 17) && test_a(s, d, n, 19) && test_a(s, d, n, 23);
}

unsigned long long safe_sqrt(unsigned long long n) {
	unsigned long long tmp = sqrt(n) + 3;
	while(1ULL * tmp * tmp > n) tmp--;
	return tmp;
}

unsigned long long next_prime(unsigned long long n) {
	while(!miller(n)) n++;
	return n;
}

unsigned long long prev_prime(unsigned long long n) {
	while(!miller(n)) n--;
	return n;
}

bool check(unsigned long long x) {
	if(x == 1ULL) return false;
	if(miller(x)) return true;
	if(binary_search(all(candidates), x)) return true;
	auto next = next_prime(safe_sqrt(x) + 1);
	if(x % next) return false;
	if(!miller(x / next)) return false;
	return x == next * prev_prime(next - 1);
}

void solve() {
	unsigned long long n;
	cin >> n;
	if(check(n)) cout << "NICE" << '\n';
	else cout << "UGLY" << '\n';
}

int32_t main() {
#define TASKNAME "icpc22_national_c"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sang();
	//cout << pre[pre.size() - 1];
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
10
1
2
3
4
5
6
7
8
9
10
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
UGLY
NICE
NICE
UGLY
NICE
NICE
NICE
UGLY
UGLY
UGLY
------------------------------    |
==================================+
*/
