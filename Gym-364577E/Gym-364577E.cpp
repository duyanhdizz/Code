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

int n, m, x;
bool b[26];
vector<int> a(26, INF);

void IU() {
	cin >> n >> m >> x;
	x *= x;
	vector<string> g(n);
	for(auto &s : g) cin >> s;
	for(int i = 0 ; i < n ; i++) {
		for(int j = 0 ; j < m ; j++) {
			if(g[i][j] == 'S') {
				for(int i1 = 0 ; i1 < n ; i1++) {
					for(int j1 = 0 ; j1 < m ; j1++) {
						if(g[i1][j1] != 'S') {
							a[g[i1][j1] - 'a'] = min(a[g[i1][j1] - 'a'], ((i1 - i) * (i1 - i)) + ((j1 - j) * (j1 - j)));
						}
					}
				}
			} else {
				b[g[i][j] - 'a'] = 1;
			}
		}
	}
	int q, cnt = 0;
	cin >> q;
	string s;
	cin >> s;
	for(auto &i: s) {
		if(i >= 'A' && i <= 'Z') {
			if(a[i - 'A'] == INF) {
				cout << -1;
				return;
			}
			else if(a[i - 'A'] > x) cnt++;
		} else if(!b[i - 'a']) {
			cout << -1;
			return;
		}
	}
	cout << cnt;
}

int32_t main() {
#define TASKNAME "Gym-364577E"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
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
3 9 4
qwertyuio
asdfghjkl
SzxcvbnmS
35
TheQuIcKbRoWnFOXjummsovertHeLazYDOG
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
------------------------------    |
==================================+
*/
