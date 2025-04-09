#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Điều kiện của phương pháp chia đôi
// - (a,b) là khoảng phân ly nghiệm
// - f liên tục và f(a)f(b) <0
 
// (a,b) là khoảng phân ly nghiệm <=> f(x) liên tục trên (a,b) và f(a)f(b) < 0

// n là số lần lặp tối đa
// n >= log_2[(b-a) * epsilon^-1]



// Định nghĩa hàm f(x)
double f(double x) {
    return pow(x, 3) - x - 2; // Hàm f(x) = x^3 - x - 2
}

// Phương pháp chia đôi (Bisection Method)
void bisection(double a, double b, double tol, int max_iter) {
    // Kiểm tra điều kiện áp dụng phương pháp chia đôi
    if (f(a) * f(b) >= 0) {
        cout << "Phương pháp chia đôi không áp dụng được với khoảng đã chọn.\n";
        return;
    }

    // Đặt số chữ số thập phân hiển thị
    cout << fixed << setprecision(10);

    // Tiêu đề bảng kết quả
    cout << setw(5) << "n"
         << setw(20) << "a_n"
         << setw(20) << "b_n"
         << setw(20) << "c_n+1"
         << setw(12) << "Dấu f(c_n)"
         << endl;
    cout << string(80, '-') << endl;

    int iter = 0;
    double c_n;

    while (iter < max_iter) {
        c_n = (a + b) / 2.0; // Trung điểm của đoạn [a, b]
        double f_c = f(c_n);

        // In kết quả từng bước lặp
        cout << setw(5) << iter
             << setw(20) << a
             << setw(20) << b
             << setw(20) << c_n
             << setw(12) << ((f_c > 0) ? "+" : "-")
             << endl;

        // Điều kiện dừng theo sai số tuyệt đối của hàm (nếu cần)
        // if (fabs(f_c) < tol) {
        //     break;
        // }

        // Cập nhật khoảng [a, b] cho bước tiếp theo
        if (f(a) * f_c < 0) {
            b = c_n;
        } else {
            a = c_n;
        }

        iter++;
    }

    // In nghiệm gần đúng cuối cùng
    cout << "Nghiệm gần đúng: x = " << c_n << " với sai số tol = " << tol << endl;
}

int main() {
    double a = 1, b = 2;       // Khoảng ban đầu chứa nghiệm
    double tol = 1e-4;         // Sai số chấp nhận được
    int max_iter = 14;         // Số lần lặp tối đa

    bisection(a, b, tol, max_iter);

    return 0;
}
