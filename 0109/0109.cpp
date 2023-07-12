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

int calculate(int x, int y, char op) {
	if(op == '+') return x + y;
	else if(op == '-') return x - y;
	else if(op == '*') return x * y;
	else return x / y;
}

void SaKaTa() {
	int n;
	cin >> n;
	cin.ignore();
	while(n--) {
		string s;
		getline(cin, s);
		stack<int> st;
		stack<char> oper;
		int j = 0;
		while(j < s.size()) {
			if(isdigit(s[j])) {
				int num = s[j] - '0';
				while(isdigit(s[j + 1])) {
					num = num * 10 + (s[j + 1] - '0');
					j++;
				}
				st.push(num);
			} else if (s[j] == '(') {
				oper.push(s[j]);
			} else if (s[j] == ')') {
				while(oper.top() != '(') {
					char op = oper.top();
					oper.pop();
					int y = st.top();
					st.pop();
					int x = st.top();
					st.pop();
					int res = calculate(x, y, op);
					st.push(res);
				}
				oper.pop();
			} else if (s[j] == '+' || s[j] == '-') {
				while (!oper.empty() && oper.top() != '(') {
					char op = oper.top();
					oper.pop();
					int y = st.top();
					st.pop();
					int x = st.top();
					st.pop();
					int res = calculate(x, y, op);
					st.push(res);
				}
				oper.push(s[j]);
			} else if (s[j] == '*' || s[j] == '/') {
				while (!oper.empty() && (oper.top() == '*' || oper.top() == '/')) {
					char op = oper.top();
					oper.pop();
					int y = st.top();
					st.pop();
					int x = st.top();
					st.pop();
					int res = calculate(x, y, op);
					st.push(res);
				}
				oper.push(s[j]);
			}
			j++;
		}

		while (!oper.empty()) {
			char op = oper.top();
			oper.pop();
			int y = st.top();
			st.pop();
			int x = st.top();
			st.pop();
			int res = calculate(x, y, op);
			st.push(res);
		}
		cout << st.top() << '\n';
	}
}

int32_t main() {
#define TASKNAME "0109"
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
