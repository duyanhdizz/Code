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
const int N = 2106 + 1e5;
const int INF = 2106 + 1e9;

int a[N], b[N];
int cnt_dif = 0; // gia tri phan biet
map<int, int> cnt, mp;

void add(int i) {
	mp[cnt[a[i]]]--;
	if (mp[cnt[a[i]]] == 0) mp.erase(cnt[a[i]]);
	if (++cnt[a[i]] == 1) {
		++cnt_dif;
	}
	mp[cnt[a[i]]]++;
}

int fake_add(int i) {
	return (cnt[a[i]] == 0);
}

void del(int i) {
	mp[cnt[a[i]]]--;
	if (mp[cnt[a[i]]] == 0) mp.erase(cnt[a[i]]);
	if (--cnt[a[i]] == 0) --cnt_dif;
	else mp[cnt[a[i]]]++;
}

void SaKaTa() {
	int n, k;
	cin >> n >> k;
	FOR(i, 1, n) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b + 1, b + n + 1);
//	FOR(i, 1, n) cout << b[i] << ' ';
//	cout << '\n';
	FOR(i, 1, n) {
		a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b;
//		cout << a[i] << ' ';
	}
//	cout << '\n';
	int best = 0;
	for (int i = 1, j = 1; i <= n; i++) {
		while (j <= n && cnt_dif + fake_add(j) <= k + 1) {
			add(j);
			j++;
		}
		best = max(best, mp.rbegin()->first);
		del(i);
	}
	cout << best;
}

int32_t main() {
#define TASKNAME "KDEL"
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
		SaKaTa();
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
