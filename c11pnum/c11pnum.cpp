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
#define int unsigned long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

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

bool solutionExists(int n, int k) {
	int product = 1;
	for(int i = 0; i < k; ++i) product *= prime[i];
	return product <= n;
}

void solve(int n, int k) {
	if(!solutionExists(n, k)) cout << "-1\n";
	else {
		int l = 0, h = prime.size() - k;
		while(l < h) {
			int m = (l + h + 1) / 2;
			bool ok = true;
			int product = 1;
			for(int i = m; i < m + k; ++i)
				if(n / product >= prime[i]) product *= prime[i];
				else ok = false;
			if(ok) l = m;
			else h = m - 1;
		}
		int res = 1;
		for(int i = l; i < l + k; ++i) res *= prime[i];
		cout << res << "\n";
	}
}

void SaKaTa() {
	int n, k;
	cin >> n >> k;
	solve(n, k);
}

int32_t main() {
#define TASKNAME "c11pnum"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sieve(3e6);
	int testcase;
	cin >> testcase;
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
