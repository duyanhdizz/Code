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

int t, aa[N];
vector<pii> v;
int pos = 0;

int power(int a, int b) {
	int res = 1;
	while(b > 0) {
		if(b & 1) res = (res * a);
		a *= a;
		b >>= 1;
	}
	return res;
}

void sinh() {
	aa[++pos] = -1;
	for(int i = 0; i <= 30; i++)
		for(int j = i + 1; j <= 30; j++)
			aa[++pos] = power(2, i) + power(2, j);
	sort(aa + 1, aa + pos + 1);
}

int32_t main() {
#define TASKNAME "SHKNUM"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	sinh();
	cin >> t;
	for(int i = 0; i < t; i++) {
		int x;
		cin >> x;
		v.pb({x, i});
	}
	sort(all(v), greater<>());
	int vtri = pos;
	for(int i = 0; i < t; i++) {
		int n = v[i].fi;
		auto poss = lower_bound(aa, aa + vtri, n) - aa - 1;
		//cout << aa[poss] << '\n';
		v[i].fi = min(n - aa[poss], aa[poss + 1] - n);
		vtri = poss + 1;
	}
	for(int i = 0; i < t; i++) swap(v[i].fi, v[i].se);
	sort(all(v));
	for(int i = 0; i < t; i++) cout << v[i].se << '\n';
	return 0;
}
/*-
INPUT
3
10
22
4
OUTPUT
0
2
1
*/