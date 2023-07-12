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

int n;

bool check(int n) {
	int t = sqrt(n);
	if(t * t == n) return true;
	else return false;
}

int32_t main() {
#define TASKNAME "demtcp"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int res = 0;
	for(int i = 2; i <= n; i++) {
		if(check(i) == true) {
			res++;
		}
	}
	cout << n + res * 2 + res * (res - 1);
	return 0;
}
/*
INPUT
4
OUTPUT
6
*/
