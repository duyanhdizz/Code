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
const int N = 9 + 1e5;
const int INF = 1e9;

int32_t main() {
#define TASKNAME "MAXLEXP2"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	cin >> n;
	vector<int> a(n), m(n);
	each(x, a) cin >> x;
	FOR(i, 0, n - 2) {
		if(i == n - 2) {
			if(a[i] < a[i + 1] && m[a[i]] <= 1 && m[a[i + 1]] <= 1) swap(a[i], a[i + 1]);
		} else {
			if(a[i] < a[i + 1]) {
				if(a[i + 1] < a[i + 2]) {
					if(m[a[i]] == 0 && m[a[i + 1]] == 0 && m[a[i + 2]] == 0) {
						m[a[i]] = 2;
						m[a[i + 1]] = 2;
						m[a[i + 2]] = 2;
						swap(a[i], a[i + 2]);
						swap(a[i + 1], a[i + 2]);
					}
				} else {
					if(m[a[i]] <= 1 && m[a[i + 1]] <= 1) {
						m[a[i]]++;
						m[a[i + 1]]++;
						swap(a[i], a[i + 1]);
					}
				}
			}
		}
	}
	FOR(i, 0, n - 1) cout << a[i] << ' ';
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
7
7 1 2 3 4 5 6
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
7 3 4 1 2 6 5
------------------------------    |
==================================+
*/