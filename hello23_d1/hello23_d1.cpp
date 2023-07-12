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
const int N = 9 + 5e5;
const int INF = 1e9;

int n, m, k;
vector<int> HUONG[N];
bool OUTPLAY[N / 1000][N / 1000];
pii NGONG[N];
int AJT[N / 1000][N / 1000];
priority_queue<pii, vector<pii>, greater<>> DA;

void YeuHuong() {
	cin >> n >> m >> k;
	FOR(i, 1, m) {
		int u, v;
		cin >> u >> v;
		HUONG[u].push_back(v);
		HUONG[v].push_back(u);
		if(u > v) swap(u, v);
		OUTPLAY[u][v] = true;
	}
	int pos = 0;
	REP(i, 1, n) {
		FOR(j, i + 1, n) {
			if(!OUTPLAY[i][j]) NGONG[++pos] = make_pair(i, j);
		}
	}
	auto IOI = [&] (int x) {
		FOR(i, 1, n)
		AJT[x][i] = 1e9;
		AJT[x][x] = 0;
		DA.push({AJT[x][x], x});
		while(!DA.empty()) {
			pii H_H = DA.top();
			DA.pop();
			if(H_H.fi != AJT[x][H_H.se]) continue;
			each(v, HUONG[H_H.se])
			if(AJT[x][v] > AJT[x][H_H.se] + 1) {
				AJT[x][v] = AJT[x][H_H.se] + 1;
				DA.push({AJT[x][v], v});
			}
		}
	};
	FOR(i, 1, n) IOI(i);
	int ans = 0;
	FOR(i, 1, pos) {
		pii KTL = NGONG[i];
		ans += (AJT[1][KTL.fi] + AJT[KTL.se][n] + 1 == k ? 1 : 0);
	}
	cout << ans;
}

int32_t main() {
#define TASKNAME "hello23_d1"
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
		YeuHuong();
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
