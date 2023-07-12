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

int t;

string add(string firstNum, string secondNum) {
	while (firstNum.size() < secondNum.size()) firstNum = '0' + firstNum;
	while (secondNum.size() < firstNum.size()) secondNum = '0' + secondNum;

	int carry = 0;
	string res = "";

	for (int i = ((int) firstNum.size()) - 1; i >= 0; i--) {
		int tmp = firstNum[i] - '0' + secondNum[i] - '0' + carry;

		carry = tmp / 10;
		tmp %= 10;
		res = (char) (tmp + '0') + res;
	}
	if (carry > 0) res = '1' + res;

	return res;
}

map<string, int> cnt;

void solve() {
	int n;
	cin >> n;
	vector<string> a(n), b(n);
	each(x, a) cin >> x, cnt[x]++;
	each(x, b) cin >> x, cnt[add(x, "1")]--;
	string s = "0000";
	int ans = 1;
	while(s != "2399") {
		cnt[add(s, "1")] += cnt[s];
		ans = max(ans, cnt[add(s, "1")]);
		//cout << cnt[add(s, "1")] << '\n';
		s = add(s, "1");
	}
	cout << ans << '\n';
	cnt.clear();
}

int32_t main() {
#define TASKNAME "MINPLACES"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	cin >> t;
	while(t--)
		solve();
	return 0;
}
/*
==================================+
INPUT:                            |
------------------------------    |
2
6
0900 0940 0950 1100 1500 1800
0910 1200 1120 1130 1900 2000
3
0900 1100 1235
1000 1200 1240
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/
