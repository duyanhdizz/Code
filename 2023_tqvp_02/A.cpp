#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 6e6 + 5;
int n, cnt, p[N];
typedef long long ll;
bool vis[100000001];
int main() {
#define taskname "FMIN"

    if (fopen(taskname".inp", "r")) {
        freopen(taskname".inp", "r", stdin);
        freopen(taskname".out", "w", stdout);
    }

    cin.tie(0)->sync_with_stdio(0);


    cin >> n;
    long long ans = 1;

    for (int i = 2; i <= n; i++) {
        if (!vis[i]) { // nếu i là số nguyên tố
            p[cnt++] = i; // thêm i vào danh sách các số nguyên tố

            for (ll s = i; s <= n; s *= i) // tính luỹ thừa t lớn nhất sao cho i^t <= n, sẽ nhân i^t vào kết quả
                ans = ans * i % mod;
        }

        // sàng o(n), đây là code rút gọn từ link trên
        for (int j = 0; j < cnt; j++) { // duyệt qua danh sách các số nguyên tố
            ll v = i * p[j];
            if (v > n) 
                break;
            vis[v] = 1;

            if (i % p[j] == 0) // kiểm tra xem số p[j] có phải số nguyên tố nhỏ nhất mà i chia hết không thì dừng lại
            // như vậy đảm bảo mỗi số chỉ được thăm đúng 1 lần
                break;
        }
    }

    cout << ans << endl;
}
