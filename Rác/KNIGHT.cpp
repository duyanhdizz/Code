# include<iostream>

using namespace std;

#define ll  long long
#define ld  double

#define sz(x)   (int)x.size()
#define all(x)  x.begin(), x.end()

#define pb  push_back
#define X   first
#define Y   second

int main()  {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x_k, y_k;   cin >> x_k >> y_k;
    int x_p, y_p;   cin >> x_p >> y_p;

    int dx = abs(x_k - x_p);
    int dy = abs(y_k - y_p);

    if (dx == 2 && dy == 1) {   cout << "Yes";  return  0;  }
    if (dx == 1 && dy == 2) {   cout << "Yes";  return  0;  }

    cout << "No";
}