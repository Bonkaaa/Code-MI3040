#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Điều kiện của phương pháp dây cung
// - (a,b) là khoảng phân ly nghiệm
// - f'(x) xác định dấu trên [a,b]
// - f''(x) xác định dấu trên [a,b]
// Công thức lặp: x_n+1 = x_n - [f(x_n)(x_n-d)]/[f(x_n)-f(d)]
// Chọn d và x_0:
// - x0 = a, d= b nếu f(b) cùng dấu với f''(x)
// - x0=b, d=a nếu f(a) cùng dấu với f''(x)
// Công thức sai số: |x_n-x*| <= f(x_n)/m <= epsilon

// Hàm f(x) = x^3 - x - 1
double f(double x) {
    return pow(x, 3) - x - 1;
}

// Đạo hàm bậc hai f''(x) = 6x (dùng để xác định điểm bắt đầu)
double f_double_prime(double x) {
    return 6 * x;
}

// Phương pháp dây cung (Secant Method)
void secant_method(double a, double b, double epsilon, int max_iter) {
    cout << fixed << setprecision(10);

    // Xác định x0 và d dựa vào dấu của f(x) và f''(x)
    double x0, d;
    if (f(a) * f_double_prime(a) > 0) {
        x0 = b;
        d = a;
    } else {
        x0 = a;
        d = b;
    }

    // In tiêu đề bảng kết quả
    cout << setw(5) << "n"
         << setw(20) << "x_n"
         << setw(20) << "|x_n - x_n-1|"
         << endl;
    cout << string(65, '-') << endl;

    int iter = 0;          // Bắt đầu từ bước lặp n = 0
    double x1, error = 0;

    // In giá trị ban đầu
    cout << setw(5) << iter
         << setw(20) << x0
         << setw(20) << "N/A"  // Sai số chưa xác định ở bước đầu
         << endl;

    iter++;  // Chuyển sang bước lặp n = 1

    while (iter <= max_iter) {
        double f_x0 = f(x0);
        double f_d = f(d);

        // Kiểm tra mẫu số khác 0
        if (fabs(f_x0 - f_d) < 1e-12) {
            cout << "Phương pháp thất bại do chia cho 0.\n";
            return;
        }

        // Công thức lặp của phương pháp dây cung
        x1 = x0 - f_x0 * (x0 - d) / (f_x0 - f_d);

        // Tính sai số tuyệt đối
        error = fabs(x1 - x0);

        // In kết quả của bước lặp hiện tại
        cout << setw(5) << iter
             << setw(20) << x1
             << setw(20) << error
             << endl;

        // Kiểm tra điều kiện dừng
        if (error < epsilon) {
            break;
        }

        // Cập nhật giá trị cho bước lặp tiếp theo
        x0 = x1;
        iter++;
    }

    // In nghiệm gần đúng
    cout << "Nghiệm gần đúng: x = " << x1 << " với sai số epsilon = " << epsilon << endl;
}

int main() {
    double a = 1, b = 2;         // Khoảng ban đầu
    double epsilon = 1e-4;       // Sai số chấp nhận được
    int max_iter = 100;          // Số lần lặp tối đa

    secant_method(a, b, epsilon, max_iter);

    return 0;
}
