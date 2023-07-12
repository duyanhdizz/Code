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
const int N = 9 + 1e7;
const int INF = 1e9;

int a, b, pre[N];

ll _100point(int l, int r) {
	ll res = 0;
	for(int i = 1; i <= r; i++)
		for(int j = 2 * i; j <= r; j += i)
			pre[j] += i;
	for(int i = l; i <= r; i++) {
		res += abs(i - pre[i]);
	}
	return res;
}

int32_t main() {
#define TASKNAME "coci1617_r6_savrsen"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> a >> b;
	cout << _100point(a, b);
	return 0;
}
