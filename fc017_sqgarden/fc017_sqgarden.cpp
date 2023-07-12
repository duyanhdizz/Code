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

struct Point {
	int x;
	int y;
	int i;
};

struct Node {
	Point p;
	Node *next;
};

class NodeList {
	private:
		Node *first = NULL;
		Node *last = NULL;
		Node* createNode(Point p) {
			Node *a = new Node;
			a->p = p;
			a->next = NULL;
			return a;
		}
	public:
		void insertLast(Point p) {
			Node *a = createNode(p);
			if (this->last == NULL) {
				this->first = a;
				this->last = a;
			} else {
				this->last->next = a;
				this->last = a;
			}
		}
		Node *getFirst() {
			return this->first;
		}
		void setFirst(Node *p) {
			this->first = p;
		}
		void removeAfterP(Node *p) {
			if (p == NULL) {
				Node *tmp = this->first;
				this->first = this->first->next;
				if (this->first == NULL) this->last = NULL;
				return;
			}
			Node *tmp = p->next;
			if (tmp == NULL) return;
			p->next = p->next->next;
			if (p->next == NULL) this->last = p;
		}
};

int cmp(Point a, Point b) {
	if (a.x - a.y == b.x - b.y) return a.x < b.x;
	return a.x - a.y < b.x - b.y;
}

int cmpx(Point a, Point b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int cmpn(NodeList a, NodeList b) {
	if (a.getFirst()->p.x - a.getFirst()->p.y == b.getFirst()->p.x - b.getFirst()->p.y)
		return (a.getFirst()->p.x > b.getFirst()->p.x);
	return a.getFirst()->p.x - a.getFirst()->p.y < b.getFirst()->p.x - b.getFirst()->p.y;
}

void getDatax(Point *a, int n, Point **ax, int *axm, int *axc, int *axc2) {
	std::sort(a, a + n, cmpx);

	int first = 0;
	a[n].x = a[n - 1].x + 1;

	for (int i = 1; i <= n; i++) {
		if (a[i].x != a[i - 1]. x) {
			axm[a[first].i] = i - first;
			axc[a[first].i] = 0;
			axc2[a[first].i] = i - first - 1;
			ax[a[first].i] = new Point[axm[a[first].i]];
			for (int j = first; j < i; j++) {
				ax[a[first].i][j - first] = a[j];
			}
			for (int j = first + 1; j < i; j++) {
				axm[a[j].i] = - a[first].i;
				axc[a[j].i] = j - first;
				axc2[a[j].i] = i - j - 1;
			}
			first = i;
		}
	}
}

void getDuongCheo(Point *a, int n, NodeList *nd) {
	std::sort(a, a + n, cmp);
	a[n].x = a[n - 1].x + 1;
	a[n].y = a[n - 1].y;
	int first = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i - 1].x - a[i - 1].y != a[i].x - a[i].y) {
			for (int j = first; j < i; j++) {
				nd[first].insertLast(a[j]);
			}
			int j = first;
			for (Node *p = nd[first].getFirst(); p != NULL; p = p ->next) {
				nd[j].setFirst(p);
				j++;
			}
			first = i;
		}
	}
}

int binSearchx(Point *axn, int m, int y) {
	int l = 0, r = m - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (axn[mid].y == y) return 1;
		else if (axn[mid].y > y) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

int binSearchy(Point *ayn, int m, int x) {
	int l = 0, r = m - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (ayn[mid].x == x) return 1;
		else if (ayn[mid].x > x) r = mid - 1;
		else l = mid + 1;
	}
	return 0;
}

Point *ax[(int) 1e5 + 1];
int axm[(int) 1e5 + 1];
int axc[(int) 1e5 + 1];
int axc2[(int) 1e5 + 1];

Point *ay[(int) 1e5 + 1];
int aym[(int) 1e5 + 1];
int ayc[(int) 1e5 + 1];
int ayc2[(int) 1e5 + 1];
Point a[(int)1e5 + 1];

int32_t main() {
#define TASKNAME "fc017_sqgarden"
	ios_base::sync_with_stdio (0);
	cin.tie (0);
	int tbegin = clock();
	if ( fopen( TASKNAME".inp", "r" ) ) {
		freopen (TASKNAME".inp", "r", stdin);
		freopen (TASKNAME".out", "w", stdout);
	}
	int n;
	

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].i = i;
	}

	NodeList nd[(int)1e5 + 1];
	getDuongCheo(a, n, nd);
	getDatax(a, n, ax, axm, axc, axc2);

	for (int i = 0; i < n; i++) {
		swap(a[i].x, a[i].y);
	}
	getDatax(a, n, ay, aym, ayc, ayc2);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < aym[i]; j++) {
			swap(ay[i][j].x, ay[i][j].y);
		}
	}

	sort(nd, nd + n, cmpn);
	int res = 0;
	for (int i = 0; i < n; i++) {
		Node *p = nd[i].getFirst();
		Node *prev = p;
		for (Node *q = nd[i].getFirst()->next; q != NULL; q = q->next) {
			if (!axc2[p->p.i] || !ayc2[p->p.i]) break;
			int xn = (axm[q->p.i] <= 0 ? -axm[q->p.i] : q->p.i);
			int yn = (aym[q->p.i] <= 0 ? -aym[q->p.i] : q->p.i);
			int iox = binSearchx(ax[xn], axm[xn], p->p.y);
			int ioy = binSearchy(ay[yn], aym[yn], p->p.x);
			res += iox && ioy;
			axc[q->p.i] -= iox;
			ayc[q->p.i] -= ioy;
			axc2[p->p.i] -= (iox && ioy);
			ayc2[p->p.i] -= (iox && ioy);
			if (!axc[q->p.i] || !ayc[q->p.i]) {
				nd[i].removeAfterP(prev);
			} else prev = q;
		}
	}

	cout << res;
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
