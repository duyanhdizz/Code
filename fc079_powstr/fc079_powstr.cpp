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
const int mod = 1e9 + 7;

ll n, k;
string s;

ll power(ll x, ll n) {
	if(n == 0) return 1;
	if(n == 1) return x;
	ll mid = power(x, n / 2);
	mid *= mid;
	mid %= mod;
	if(n % 2 == 1) mid *= x;
	return mid;
}

int32_t main() {
#define TASKNAME "fc079_powstr"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> k >> s;
	if(k == 1) cout << power(2, n);
	else if(k == 2 && n <= 2000) {
		for(int i = 0; i < s.size(); i++) 
	}
	return 0;
}
/*
INPUT
4 2
free
---
12 3
whysoserious
OUTPUT
24
---
8656
*/
