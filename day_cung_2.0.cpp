#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

// Hàm f(x) = x^3 - x - 1
double f(double x) {
    return pow(x, 3) - x - 1;
}

// Đạo hàm bậc hai f''(x) = 6x
double f_double_prime(double x) {
    return 6 * x;
}

// Tìm min của đạo hàm cấp 2 trên đoạn [a, b]
// Vì hàm 6x là đơn điệu tăng, min tại a nếu a < b
double find_min_second_derivative(double a, double b) {
    return min(fabs(f_double_prime(a)), fabs(f_double_prime(b)));
}

// Phương pháp dây cung có in sai số lý thuyết
void secant_method_with_error(double a, double b, double epsilon, int max_iter) {
    cout << fixed << setprecision(10);

    // Xác định x0 và d dựa vào dấu của f và f''
    double x0, d;
    if (f(a) * f_double_prime(a) > 0) {
        x0 = b;
        d = a;
    } else {
        x0 = a;
        d = b;
    }

    // Tính m = min |f''(x)| trên đoạn [a, b]
    double m = find_min_second_derivative(a, b);

    // In tiêu đề bảng
    cout << setw(5) << "n"
         << setw(20) << "x_n"
         << setw(20) << "|x_n - x_n-1|"
         << setw(25) << "Sai số lý thuyết"
         << endl;
    cout << string(90, '-') << endl;

    int iter = 0;
    double x1, error = 0;

    // Bước đầu tiên
    cout << setw(5) << iter
         << setw(20) << x0
         << setw(20) << "N/A"
         << setw(25) << "N/A"
         << endl;

    iter++;

    while (iter <= max_iter) {
        double f_x0 = f(x0);
        double f_d = f(d);

        if (fabs(f_x0 - f_d) < 1e-12) {
            cout << "Phương pháp thất bại do chia cho 0.\n";
            return;
        }

        // Công thức lặp
        x1 = x0 - f_x0 * (x0 - d) / (f_x0 - f_d);
        error = fabs(x1 - x0);

        // Tính sai số lý thuyết
        double theoretical_error = (m > 0) ? fabs(f(x1)) / m : -1; // Nếu m = 0 thì không tính được

        // In kết quả
        cout << setw(5) << iter
             << setw(20) << x1
             << setw(20) << error
             << setw(25) << ((m > 0) ? to_string(theoretical_error) : "Không xác định")
             << endl;

        if (error < epsilon) {
            break;
        }

        x0 = x1;
        iter++;
    }

    cout << "Nghiệm gần đúng: x = " << x1 << " với sai số epsilon = " << epsilon << endl;
}

int main() {
    double a = 1, b = 2;        // Khoảng ban đầu
    double epsilon = 1e-4;      // Sai số chấp nhận
    int max_iter = 100;         // Số lần lặp tối đa

    secant_method_with_error(a, b, epsilon, max_iter);

    return 0;
}
