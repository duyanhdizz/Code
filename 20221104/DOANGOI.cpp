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
const int N = 9 + 1e3;
const int INF = 1e9;

int n, res = 1, d[N];
vector<pii> v;

int find(int i, int res) {
	if(i == n - 1) return res;
	int kthuc = v[i].se, vtri = 0;
	bool ktra = false;
	for(int j = i + 1; j < n; j++)
		if(v[j].fi == kthuc) {
			kthuc = v[j].se;
			ktra = true;
			vtri = j;
			d[j]++;
			res++;
			break;
		}
	if(ktra == true) return find(vtri, res);
	else return res;
}

int32_t main() {
#define TASKNAME "DOANGOI"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	fill(d, d + N, 0);
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		v.pb({a, b});
	}
	sort(all(v));
	int ans = 0;
	for(int i = 0; i < n; i++)
		if(d[i] == 0) ans = max(ans, find(i, 1));
	cout << ans;
	return 0;
}
/*
INPUT
5
2 7
1 3
7 9
3 4
4 5
OUTPUT
3
*/
