#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast","unroll-loops")
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

int n;
vector<int> prime_n[N + 100];
vector<bool> check(N, true);

void Sieve() {
	FOR(i, 2, N) {
		if(check[i] == true) {
			prime_n[i].pb(i);
			for(int j = 2 * i; j <= N; j += i) {
				check[j] = false;
				prime_n[j].pb(i);
			}
		}
	}
}

int32_t main() {
#define TASKNAME "TUNT"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	Sieve();
	cin >> n;
	ll sum = 0;
	FOR(i, 1, n) {
		int a, b;
		cin >> a >> b;
		sum += prime_n[a][b - 1];
	}
	cout << sum;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
1
30 3
---
5
30 3
64 1
105 2
1001 3
5474 4
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
5
--- 
48
------------------------------    |
==================================+
*/
