#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// Điều kiện phương pháp tiếp tuyến:
// - (a,b) là khoảng cách ly nghiệm
// - f'(x) xác định dấu trên [a,b]
// - f''(x) xác định dấu trên [a,b]
// Chọn x0 = a nếu f(x0)f''(x0)>0
// Công thức lặp: x_n+1 = x_n -(f(x_n)/f'(x_n))
// Điều kiện dừng: |x_n-x_n-1| <= căn bậc 2 (2*epsilon*m1/M2)
// m1 = min |f'(x)| và m2 = max |f''(x)|

// Định nghĩa hàm f(x), đạo hàm cấp 1 f'(x) và đạo hàm cấp 2 f''(x)
double f(double x) {
    return pow(x,5)-17;
}

double df(double x) {
    return 5*pow(x,4);
}

double ddf(double x) {
    return 20*pow(x,3);
}

// Phương pháp Newton-Raphson với điều kiện dừng nâng cao
void newtonRaphson(double (*f)(double), double (*df)(double), double (*ddf)(double), double a, double b, double epsilon) {
    // Chọn x0 theo dấu của f(a) * f''(a)
    double x_n = (f(a) * ddf(a) > 0) ? a : b;
    int n = 0;
    double x_prev = x_n;

    // Tính m1 = min |f'(x)| và M2 = max |f''(x)| trên đoạn [a, b]
    double m1 = min(fabs(df(a)), fabs(df(b)));
    double M2 = max(fabs(ddf(a)), fabs(ddf(b)));

    // Tính ngưỡng dừng theo công thức sai số nâng cao
    double threshold = sqrt((2 * epsilon * m1) / M2);

    // In tiêu đề bảng kết quả
    cout << "--------------------------------------------------\n";
    cout << "|  n  |    x_n     | |x_n - x_(n-1)|             |\n";
    cout << "--------------------------------------------------\n";

    // Lặp Newton-Raphson
    while (true) {
        double x_next = x_n - f(x_n) / df(x_n);  // Công thức Newton-Raphson
        double diff = fabs(x_next - x_n);        // Sai số giữa hai lần lặp liên tiếp

        // In kết quả mỗi vòng lặp
        cout << "| " << setw(3) << n 
             << " | " << setw(12) << fixed << setprecision(10) << x_n 
             << " | " << setw(22) << diff << " |\n";

        // Dừng nếu sai số nhỏ hơn ngưỡng
        if (diff <= threshold) break;

        // Cập nhật giá trị cho lần lặp tiếp theo
        x_n = x_next;
        n++;
    }

    cout << "--------------------------------------------------\n";
}

int main() {
    double a, b, epsilon;

    // Nhập khoảng cách ly nghiệm và sai số cho phép
    cout << "Nhập khoảng cách ly nghiệm (a, b): ";
    cin >> a >> b;
    cout << "Nhập sai số epsilon: ";
    cin >> epsilon;

    // Gọi hàm giải phương trình theo phương pháp Newton-Raphson
    newtonRaphson(f, df, ddf, a, b, epsilon);

    return 0;
}
