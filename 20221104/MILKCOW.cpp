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
const int N = 9 + 5e3;
const int INF = 1e9;

int n;
//d[N];
vector<pii> v;

int findmax(int i, int kthuc) {
	int vtri;
	bool ktra = false;
	for(int j = i + 1; j < n; j++)
		if(kthuc >= v[j].fi) {
			kthuc = v[j].se;
			ktra = true;
			//d[j]++;
			vtri = j;
			break;
		}
	if(ktra == true) return findmax(vtri, kthuc);
	else return kthuc;
}

int32_t main() {
#define TASKNAME "MILKCOW"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.pb({a, b});
	}
	sort(all(v));
	int ansmax = 0, ansmin = INF;
	for(int i = 0; i < n; i++) ansmax = max(ansmax, findmax(i, v[i].se) - v[i].fi);
	for(int i = 0; i + 1 < n; i++)
		if(v[i].se < v[i + 1].fi) ansmin = min(ansmin, v[i + 1].fi - v[i].se);
	cout << ansmax << ' ' << ansmin;
	return 0;
}
/*
INPUT
3
300 1000
700 1200
1500 2100
---

OUTPUT
900 300
---
*/