#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
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
const int N = 9 + 1e3 + 1e6;
const int INF = 1e9;

vector<int> prime;
ll pref[N];
vector<int> lpf;
void sieve(int n) {
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);

	for(int x = 3; x <= n; x += 2) {
		if(lpf[x] == 2) prime.push_back(lpf[x] = x);
		for(int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; i++) {
			lpf[prime[i] * x] = prime[i];
		}
	}
	for(int i = 0; i < n - 3; i++) {
		pref[i] = 1ll * prime[i] * prime[i + 1] * prime[i + 2];
	}
}

void IU() {
	ll n;
	cin >> n;
	cout << (n < 30 ? -1 : *--upper_bound(pref, pref + N, n)) << '\n';
}

int32_t main() {
#define TASKNAME "3primes"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sieve(1e6 + 1e2);
	int testcase = 1;
//    cin >> testcase;
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
