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

bool cmp(int a, int b) {
	string a_ = to_string(a), b_ = to_string(b);
	if(a_.size() == b_.size()) return a > b;
	else if(a_.size() > b_.size()) {
		string mid = a_.substr(0, b_.size());
		int aa = stoi(mid);
		int bb = stoi(b_);
//		cout << aa << ' ' << bb;
		if(aa == bb) {
			int pos = b_.size();
			while(a_[pos] == a_[b_.size() - 1]) pos++;
			if(a_[pos] > a_[b_.size() - 1]) return true;
			else return false;
		}
		return aa > bb;
	} else {
		string mid = b_.substr(0, a_.size());
		int bb = stoi(mid);
		int aa = stoi(a_);
		if(aa == bb) {
			int pos = a_.size();
			while(b_[pos] == b_[a_.size() - 1]) pos++;
			if(b_[pos] < b_[b_.size() - 1]) return false;
			else return true;
		}
		return aa > bb;
	} ///
}

void SaKaTa() {
	int n;
	cin >> n;
	vector<int> a(n);
	each(x, a) cin >> x;
	sort(all(a), cmp);
	each(x, a) cout << x;
}

int32_t main() {
#define TASKNAME "MAXNUM"
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
