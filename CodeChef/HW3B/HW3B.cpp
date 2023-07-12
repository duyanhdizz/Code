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
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;
}

int32_t main() {
#define TASKNAME "HW3B"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 4; i <= n - 4; i++)
		if(check(i) == false && check(n - i) == false) return cout << i << ' ' << n - i, 0;
	return 0;
}
/*
INPUT
OUTPUT
*/
