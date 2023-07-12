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

int32_t main() {
#define TASKNAME "pabc"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	int res = 0;
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			int j = n / i;
			for(int z = i; z * z <= j; z++) {
				if(j % z == 0) res++;
			}
		}
	}
	cout << res;
	return 0;
}
/*
INPUT
8
OUTPUT
3
*/
