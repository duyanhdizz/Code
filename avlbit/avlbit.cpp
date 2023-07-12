#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#pragma GCC optimize("Ofast,O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define FOR(i, a, b) for (int i = (a); i <= (int) (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (int) (b); --i)
#define REP(i, a, b) for (int i = (a); i < (int) (b); ++i)
#define each(a, x) for (auto &a : x)
#define fi first
#define se second
#define pb push_back
#define int long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 2e7;
const int INF = 1e9;

int n, q;
int a[N], b[N];
int nxt[N];
map<int, int> pos;

int comp_Max(int a, int b) {
	return max(a, b);
}

int comp_Min(int a, int b) {
	return min(a, b);
}

int comp_Gcd(int a, int b) {
	return __gcd(a, b);
}

struct ST {
	vector<int> f[18];
	int n;
	ST (int n) : n(n) {
		FOR(i, 0, 17) f[i].resize(n + 5);
	}
	void build(int a[], int n, int compare(int, int)) {
		FOR(i, 1, n) f[0][i] = a[i];
		for (int k = 1; (1 << k) <= n; ++k) {
			for (int i = 1; i + (1 << k) - 1 <= n; ++i) {
				f[k][i] = compare(f[k - 1][i], f[k - 1][i + (1 << (k - 1))]);
			}
		}
	}
	int get(int l, int r, int compare(int, int)) {
		int k = __lg(r - l + 1);
		return compare(f[k][l], f[k][r - (1 << k) + 1]);
	}
};

int32_t main() {
#define TASKNAME "avlbit"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n >> q;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n - 1) b[i] = a[i + 1] - a[i];
	FORD(i, n, 1) {
		if (pos[a[i]]) nxt[i] = pos[a[i]];
		else nxt[i] = INF;
		pos[a[i]] = i;
	}
	ST stMax(n), stMin(n), stGcd(n - 1), stPos(n);
	stMax.build(a, n, comp_Max);
	stMin.build(a, n, comp_Min);
	stGcd.build(b, n - 1, comp_Gcd);
	stPos.build(nxt, n, comp_Min);
	while (q--) {
		int l, r;
		cin >> l >> r;
		int ma = stMax.get(l, r, comp_Max);
		int mi = stMin.get(l, r, comp_Min);
		if(ma == mi || (ma - mi) % (r - l) != 0) {
			cout << "NO" << '\n';
			continue;
		}
		int di__ = (ma - mi) / (r - l);
		int curr__Gcd = abs(stGcd.get(l, r - 1, comp_Gcd));
		int p_o_s = stPos.get(l, r, comp_Min);
		cout << (p_o_s > r && curr__Gcd == di__ ? "YES" : "NO") << '\n';
	}
	return 0;
}
/*
INPUT
5 2
1 3 2 5 4
1 5
2 4
OUTPUT
YES
NO
*/
