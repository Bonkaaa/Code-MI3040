#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Điều kiện
// - Tập D thoả mãn, chỉ ra các phần tử thoả mãn tập D
// - |J| < 1
// Tìm đạo hàm riêng các phần tử sau đó tính tổng theo chuẩn hàng
// Sau đó tính hệ số k = max{row1,row2,row3} < 1 là thoả mãn điều kiện hội tụ
// Chọn x0 tuỳ ý thoả mãn D
// x1k = ..., x2k = ..., x3k = ...
// Điều kiện dừng: ||x_n-x*||_vô cùng <= ||x_n-x_n-1||_vô cùng *k/(1-k) <= epsilon
// => ||x_n-x_n-1||_vô cùng <= epsilon*(1-k)/k


// Định nghĩa hàm F1 và F2
double f1(double x, double y) {
    return (1.0 / 3.0) * cos(y) + (1.0 / 3.0);
}

double f2(double x, double y) {
    return (1.0 / 4.0) * sin(x) + (1.0 / 2.0);
}

// Tính chuẩn Euclid ||x_n - x_n-1||
double norm(double x_new, double x_old, double y_new, double y_old) {
    return sqrt((x_new - x_old) * (x_new - x_old) + (y_new - y_old) * (y_new - y_old));
}

int main() {
    const double epsilon = 1e-5;
    const double k = 1.0 / 3.0;
    const double threshold = epsilon * (1 - k) / k;

    double x_old = 0.0, y_old = 0.0;
    double x_new, y_new;
    int n = 1;

    cout << fixed << setprecision(6);
    cout << "n\t x_n\t\t\t ||x_n - x_n-1||_vô cùng\n";

    do {
        x_new = f1(x_old, y_old);
        y_new = f2(x_old, y_old);
        double err = norm(x_new, x_old, y_new, y_old);

        cout << n << "\t " << "(" << x_new << "," << y_new << ")" << "\t " << err << endl;

        if (err <= threshold)
            break;

        x_old = x_new;
        y_old = y_new;
        n++;
    } while (n < 1000); // giới hạn tránh vòng lặp vô tận
    cout << "\nNghiệm x1 = " << x_new
     << ", x2 = " << y_new << endl;
    return 0;
}
