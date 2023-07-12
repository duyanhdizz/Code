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
vector<int> a, b, c, d, cnt, cnt2, sum;

int32_t main() {
#define TASKNAME "cvp_sxtk21"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> n;
	for(int i = 0; i < n; i++) {
		int aa, bb, cc, dd;
		cin >> aa >> bb >> cc >> dd;
		a.pb(aa);
		b.pb(bb);
		c.pb(cc);
		d.pb(dd);
	}
	for(int i = 0; i < a.size(); i++)
		for(int j = 0; j < b.size(); j++)
			cnt.pb(a[i] + b[j]);
	sort(all(cnt));
	for(int i = 0; i < c.size(); i++)
		for(int j = 0; j < d.size(); j++)
			cnt2.pb(-(c[i] + d[j]));
	sort(all(cnt2));
	int res = 0;
	for(int lo = 0, low = 0; lo < cnt.size(), low < cnt2.size();) {
		while(lo < cnt.size() && cnt[lo] < cnt2[low]) lo++;
		while(low < cnt2.size() && cnt[lo] > cnt2[low]) low++;
		if(lo == cnt.size() || low == cnt2.size()) break;
		if(cnt[lo] == cnt2[low]) {
			int r = cnt[lo], ans = 0, ans2 = 0;
			while(cnt[lo] == r && lo < cnt.size()) lo++, ans++;
			while(cnt2[low] == r && low < cnt2.size()) low++, ans2++;
			res += ans * ans2;
		}
	}
	cout << res;
	return 0;
}
/*
INPUT
6
-45 22 42 -16
-41 -27 56 30
-36 53 -37 77
-36 30 -75 -46
26 -38 -10 62
-32 -54 -6 45
OUTPUT
5
*/
