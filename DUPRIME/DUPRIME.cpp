#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
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
const int N = 9 + 1e5;
const int INF = 1e9;

int n;

vector<int> prime;
vector<int> lpf;
vector<bool> check;
void sieve(int n) {
	prime.assign(1, 2);
	lpf.assign(n + 1, 2);

	for (int x = 3; x <= n; x += 2) {
		if (lpf[x] == 2) prime.push_back(lpf[x] = x);
		for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i)
			lpf[prime[i] * x] = prime[i];
	}
}

int32_t main() {
#define TASKNAME "DUPRIME"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sieve(1e7);
	cin >> n;
	each(x, prime) {
		if(2 * x + 1 == lpf[2 * x + 1]) {
			n--;
			if(n == 0) return cout << x, 0;
		}
	}
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
