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

int k, m, cnt[256];
string s;

int32_t main() {
#define TASKNAME "DELSTR"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> m >> k >> s;
	int n = s.size();
	vector<bool> c(26);
	for(int i = 0; i < s.size(); i++) c[s[i] - 'A'] = true;
	vector<char> ch;
	for(int i = 0; i < 26; i++)
		if (c[i]) ch.pb(i + 'A');
	for(int i = 0; i < m; i++) cnt[ch[i]] = i;
	vector<int> a(m);
	int res = n;
	for (int l = 0, r = 0; l < n; l++) {
		if (l) a[cnt[s[l - 1]]]--;
		while (r < n && *min_element(all(a)) < k) a[cnt[s[r++]]]++;
		if (r == n) break;
		res = min(res, accumulate(all(a), 0) - m * k);
	}
	cout << res;
	return 0;
}
/*
INPUT
3 2
ABBABCABBCCCBA
---
3 2
ABABAAACCC
OUTPUT
1
---
2
*/