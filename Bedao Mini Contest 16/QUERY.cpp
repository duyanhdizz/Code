//https://oj.vnoi.info/problem/bedao_m16_query
#include<iostream>
#include<vector>
#define lli long long int

using namespace std;

const int N=500001;
lli seg_tree[4*N];
int n, a[N];
vector<lli> lazy_AND(4*N,-1), lazy(4*N,-1);

void fix_1(int id, int l, int r) {
	if (lazy_AND[id]==-1)
		return;
	seg_tree[id]&=lazy_AND[id];
	if (l!=r) {
		lazy_AND[id*2]&=lazy_AND[id];
		lazy_AND[id*2+1]&=lazy_AND[id];
	}
	lazy_AND[id]=-1;
}
void fix_2(int id, int l, int r) {
	if (lazy[id]==-1)
		return;
	seg_tree[id]=lazy[id];
	lazy_AND[id]=-1;
	if (l!=r) {
		lazy[id*2]=lazy[id*2+1]=lazy[id];
		lazy_AND[id*2]=lazy_AND[id*2+1]=-1;
	}
	lazy[id]=-1;
}
void build(int id, int l, int r) {
	if (l==r) {
		seg_tree[id]= a[l];
		return;
	}
	int mid=(l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);
	seg_tree[id]= seg_tree[id*2] | seg_tree[id*2+1];
}
void update_1(int id, int l, int r, int u, int v, lli val) {
	fix_1(id, l, r);
	fix_2(id, l, r);
	if (l>v || r<u)
		return;
	if (l>=u && r<=v) {
		if (lazy[id]!=-1) {
			lazy[id]&=val;
			fix_2(id, l, r);
		} else {
			lazy_AND[id]&=val;
			fix_1(id, l, r);
		}
		return;
	}
	int mid=(l+r)/2;
	update_1(id*2, l, mid, u, v, val);
	update_1(id*2+1, mid+1, r, u, v, val);
	seg_tree[id]= seg_tree[id*2] | seg_tree[id*2+1];
}
void update_2(int id, int l, int r, int u, int v, lli val) {
	fix_1(id, l, r);
	fix_2(id, l, r);
	if (l>v || r<u)
		return;
	if (l>=u && r<=v) {
		lazy_AND[id]=-1;
		lazy[id]=val;
		fix_2(id, l, r);
		return;
	}
	int mid=(l+r)/2;
	update_2(id*2, l, mid, u, v, val);
	update_2(id*2+1, mid+1, r, u, v, val);
	seg_tree[id]= seg_tree[id*2] | seg_tree[id*2+1];
}
int get(int id, int l, int r, int u, int v) {
	fix_1(id, l, r);
	fix_2(id, l, r);
	if (l>v || r<u)
		return 0;
	if (l>=u && r<=v)
		return seg_tree[id];
	int mid=(l+r)/2;
	int get1=get(id*2, l, mid, u, v);
	int get2=get(id*2+1, mid+1, r, u, v);
	return get1|get2;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int q;
	cin>>n>>q;
	for (int i=1; i<=n; i++)
		cin>>a[i];
	build(1,1,n);
	while(q--) {
		int type, l, r;
		lli x;
		cin>>type>>l>>r;
		if (type==1) {
			cin>>x;
			update_1(1, 1, n, l, r, x);
		} else if (type==2) {
			cin>>x;
			update_2(1, 1, n, l, r, x);
		} else	cout<<get(1, 1, n, l, r)<<"\n";
	}
	return 0;
}
