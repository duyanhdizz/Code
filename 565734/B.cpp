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

vector<int> visited;
vector<int> lt;

void dfs(int pos, int nhay, int &_) {
	if (pos == lt.size() - 1) {
		_ = min(_, visited[pos]);
		return;
	}
	for (int i = 1; i <= nhay && pos + i < lt.size(); i++) {
		if (lt[pos + i] && visited[pos + i] > visited[pos] + 1) {
			visited[pos + i] = visited[pos] + 1;
			dfs(pos + i, nhay, _);
		}
	}
}

void SaKaTa() {
	int n, d;
	cin >> n >> d;
	string s;
	cin >> s;
	visited.resize(n, n + 2106);
	lt.resize(n);
	FOR(i, 0, n - 1) lt[i] = s[i] - '0';
	visited[0] = 0;
	int _ = n;
	dfs(0, d, _);
	cout << (_ == n ? -1 : _);
}

int32_t main() {
#define TASKNAME "B"
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
		SaKaTa();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
8 4
10010101
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
2
------------------------------    |
==================================+
*/
