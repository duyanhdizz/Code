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
const int N = 9 + 1e5;
const int INF = 1e9;

int a[N], b[N], m[N];
vector<deque<int>> ans(N);

void YeuHuong() {
	int n, k;
	cin >> n >> k;
	int DA = 0;
	FOR(i, 1, n) {
		cin >> a[i] >> b[i];
		m[i] = 0;
		if(ans[a[i]].size() == 0) {
			DA++;
			m[i] = 2;
		} else {
			if(ans[b[i]].size() == 0) {
				DA++;
				m[i] = 1;
			}
			ans[b[i]].pb(i);
		}
		ans[a[i]].pb(i);
	}
	cout << DA << '\n';
	FOR(i, 2, n) {
		DA--;
		int mid = a[i - 1];
		while(true) {
			while(ans[mid].size() != 0 && m[ans[mid].front()] == 2) ans[mid].pop_front();
			if(ans[mid].size() == 0) break;
			else {
				int top = ans[mid].front();
				if(m[top] == 1) {
					m[top] = 2;
					mid = b[top];
				} else {
					if(m[top] == 0) {
						DA++;
						if(b[top] == mid) m[top] = 1;
						else m[top] = 2;
						break;
					}
				}
			}
		}
		cout << DA << '\n';
	}
}

int32_t main() {
#define TASKNAME "TAMELESS"
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
