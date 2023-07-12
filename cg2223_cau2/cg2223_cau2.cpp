#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast","unroll-loops")
#define FOR(i, a, b) for(int i=(a), _b=(b); i<_b; ++i)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int a, b;

int32_t main() {
#define TASKNAME "CAU2"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> a >> b;
	int lcm = (a * b) / (__gcd(a, b));
	int res = 1;
	for(int i = 2; i * i <= sqrt(lcm); i++)
		if(lcm % i == 0) {
			if(__gcd(a, b) == __gcd(i, lcm / i)) res++;
		}
	cout << res * 2;
	return 0;
}
/*
INPUT
6 8
OUTPUT
4
*/
