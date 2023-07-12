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

map<int, int> m;

int bin_pow(int a, int b) {
	int res = 1;
	while(b > 0) {
		if(b & 1) res *= a;
		a *= a;
		b >>= 1;
	}
	return res;
}

void IU() {
	int n;
	cin >> n;
	FOR(i, 1, n) {
		int x;
		cin >> x;
		while(x > 1) {
			int p = lpf[x];
			if(p * p > x) break;
			int cnt = 0;
			while(x % p == 0) x /= p, cnt++;
			m[p] += cnt;
		}
		if(x > 1) {
			m[x]++;
		}
	}
	FOR(i, 2, 1e6 + 3) {
		int x = i;
		while(x > 1) {
			int p = lpf[x];
			if(p * p > x) break;
			int cnt = 0;
			while(x % p == 0) x /= p, cnt++;
			if(cnt > m[p]) {
				cout << i;
				return;
			}
		}
		if(x > 1) {
			if(m[x] == 0) {
				cout << i;
				return;
			}
		}
	}
}

int32_t main() {
#define TASKNAME "FINDNUM"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sieve(1e6 + 3);
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
