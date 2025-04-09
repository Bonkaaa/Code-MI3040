#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Định nghĩa hàm F1, F2, F3
double f1(double x, double y, double z) {
    return (13-pow(y,2)+4*z)/15;
}

double f2(double x, double y, double z) {
    return (11+z-pow(x,2))/10;
}

double f3(double x, double y, double z) {
    return (22+pow(y,3))/25;
}

// Tính chuẩn Euclid ||x_n - x_n-1||
double norm(double x_new, double x_old, double y_new, double y_old, double z_new, double z_old) {
    return sqrt(pow(x_new - x_old, 2) + pow(y_new - y_old, 2) + pow(z_new - z_old, 2));
}

int main() {
    const double epsilon = 0.5e-6;
    const double k = 7.0/15.0;
    const double threshold = epsilon * (1 - k) / k;

    double x_old = 1.0, y_old = 1.0, z_old = 0.5;
    double x_new, y_new, z_new;
    int n = 1;

    cout << fixed << setprecision(7);
    cout << "n\t x_n\t\t\t\t\t ||x_n - x_n-1||_vô cùng\n";

    do {
        x_new = f1(x_old, y_old, z_old);
        y_new = f2(x_old, y_old, z_old);
        z_new = f3(x_old, y_old, z_old);

        double err = norm(x_new, x_old, y_new, y_old, z_new, z_old);

        cout << n << "\t " << "(" << x_new << "," << y_new << "," << z_new << ")" << "\t " << err << endl;

        if (err <= threshold)
            break;

        x_old = x_new;
        y_old = y_new;
        z_old = z_new;
        n++;
    } while (n < 1000); // tránh lặp vô hạn
    cout << "\nNghiệm x1 = " << x_new
     << ", x2 = " << y_new
     << ", x3 = " << z_new << endl;
    return 0;
}
