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

string s;
map<string, int> m;

string chuanhoa(string s) {
	while(s[0] == '0') s.erase(0, 1);
	return s;
}

unsigned long long s_stoi(string s) {
	unsigned long long res = 0;
	each(x, s) res = res * 10 + (x - 48);
	return res;
}

bool check(string s) {
	if(s == "") return false;
	unsigned long long doi = s_stoi(s);
	return (doi % 3 == 0 ? true : false);
}

int32_t main() {
#define TASKNAME "DELDIGIT"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s;
	if(check(chuanhoa(s))) m[chuanhoa(s)]++;
	int j = 1;
	while(j < s.size()) {
		FOR(i, 0, s.size() - j) {
			string res = s;
			res.erase(i, j);
			//if(check(chuanhoa(res))) m[chuanhoa(res)]++;
			cout << chuanhoa(res) << '\n';
		}
		j++;
	}
	cout << m.size();
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
1008
---
6398030
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
3
------------------------------    |
==================================+
*/
