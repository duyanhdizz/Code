#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

string s;

int32_t main() {
#define TASKNAME "trik"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> s;
	int res = 1;
	for(auto i : s) {
		if(i == 'A') {
			if(res == 1) res++;
			else if(res == 2) res--;
		}
		if(i == 'B') {
			if(res == 2) res++;
			else if(res == 3) res--;
		}
		if(i == 'C') {
			if(res == 3) res -= 2;
			else if(res == 1) res += 2;
		}
	}
	cout << res;
	return 0;
}
/*
INPUT
OUTPUT
*/
