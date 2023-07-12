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

ll x, y;

int32_t main() {
#define TASKNAME "cvp_abu"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> x >> y;
	ll sum_x = 0, sum_y = 0;
	FOR(i, 1, sqrt(x)) {
		if(x % i == 0) {
			sum_x += i;
			if(i * i != x) sum_x += (x / i);
		}
	}
	FOR(i, 1, sqrt(y)) {
		if(y % i == 0) {
			sum_y += i;
			if(i * i != y) sum_y += (y / i);
		}
	}
	if(sum_x / __gcd(sum_x, x) == sum_y / __gcd(sum_y, y) && x / __gcd(sum_x, x) == y / __gcd(sum_y, y)) cout << sum_x / __gcd(sum_x, x) << ' ' << x / __gcd(sum_x, x);
	else cout << -1;
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
30
140
---
3
4
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
12
5
--- 
-1
------------------------------    |
==================================+
*/
