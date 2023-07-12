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

int a, b;

int32_t main() {
#define TASKNAME "spavanac"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> a >> b;
	if(b >= 45) b -= 45;
	else {
		b += 15;
		a--;
		if(a == -1) a = 23;
	}
	cout << a << ' ' << b;
	return 0;
}
/*
INPUT
10 10
OUTPUT
9 25
*/
