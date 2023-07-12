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
#define ll long long
#define all(a) a.begin(),a.end()
typedef pair<int, int> pii;
const int N = 9 + 1e6;
const int INF = 1e9;

int c[N], d[N];

void YeuHuong() {
	int n, k;
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> c[i];
	}
	vector<int> div0, div1, div2;
	FOR(i, 1, n) {
		cin >> d[i];
		d[i] %= 3;
		if(d[i] == 0) div0.pb(c[i]);
		else if(d[i] == 1) div1.pb(c[i]);
		else div2.pb(c[i]);
	}
	sort(all(div0));
	sort(all(div1));
	sort(all(div2));
	int ans = 0;
	int sum = 0;
	int pos = 0;
	while(pos < div0.size() && sum + div0[pos] <= k) sum += div0[pos], pos++, ans++;
	pos = 0;
	while(pos < div1.size() && pos < div2.size() && sum + div1[pos] + div2[pos] <= k) sum += div1[pos] + div2[pos], pos++, ans += 2;
	int ans_s = 0;
	sum = 0;
	pos = 0;
	while(pos < div1.size() && pos < div2.size() &&sum + div1[pos] + div2[pos] <= k) sum += div1[pos] + div2[pos], pos++, ans_s += 2;
	while(pos < div0.size() && sum + div0[pos] <= k) sum += div0[pos], pos++, ans_s++;
	cout << max(ans, ans_s) << '\n';
}

int32_t main() {
#define TASKNAME "hello23_c1"
	ios_base::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int testcase = 1;
//    cin >> testcase;
	while(testcase--)
		YeuHuong();
	cerr << '\n' << "Runtime: " << (clock() - tbegin) << " ms\n";
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
