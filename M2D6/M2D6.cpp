#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    // Xử lý từng test case
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        // Khởi tạo biến đếm số lượng phép tính
        int count = 0;

        // Xử lý cho đến khi n = 1
        while (n != 1) {
            // Nếu n không chia hết cho 6, ta nhân n với 2
            if (n % 6 != 0) {
                n *= 2;
                count++;
            }
            // Ngược lại, ta chia n cho 6
            else {
                n /= 6;
                count++;
            }
            
            // Kiểm tra nếu n không thể chia hết cho 6 và không thể nhân với 2 nữa
            if (n % 6 != 0 && n % 2 != 1) {
                cout << "-1" << '\n';
                break;
            }
        }

        // In ra kết quả nếu n = 1
        if (n == 1) {
            cout << count << '\n';
        }
    }

    return 0;
}
