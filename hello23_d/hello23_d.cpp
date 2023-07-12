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
const int N = 9 + 5e3;
const int INF = 1e9;
const int NMAX = 5e5;

int n,m,k;
int d[2][NMAX], sl[2][NMAX];
map<pii, bool> ok;
vector<int> adj[NMAX];

void BFS(int id, int st) {
	queue<int> q;
	FOR(i, 1, n) d[id][i]=-1;
	d[id][st]=0;
	q.push(st);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(auto i : adj[x])
			if(d[id][i] == -1) d[id][i] = d[id][x] + 1, q.push(i);
	}
}

void IU() {
	cin >> n >> m >> k;
	for(int i = 1, u, v; i <= m; i++) {
		cin >> u >> v;
		ok[ {u, v}] = true;
		ok[ {v, u}] = true;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	BFS(0, 1);
	BFS(1, n);
	if(d[0][n] < k) {
		cout << 0;
		return;
	}
	if(d[0][n] > k) {
		int ans = 0;
		REP(i, 1, n) {
			FOR(j, i + 1, n) {
				if(!ok[ {i, j}] && min(d[0][i] + d[1][j], d[1][i] + d[0][j]) + 1 == k) ++ans;
			}
		}
		cout << ans;
	}
	if(d[0][n] == k) {
		int ans = 0;
		REP(i, 1, n) {
			FOR(j, i + 1, n) {
				if(!ok[ {i, j}] && min(d[0][i] + d[1][j], d[1][i] + d[0][j]) + 1 >= k) ++ans;
			}
		}
		cout << ans;
	}
}

int32_t main() {
#define TASKNAME "hello23_d"
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

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
