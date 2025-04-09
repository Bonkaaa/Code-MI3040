#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Công thức lặp: x_k+1 = x_k - J(x_k)^-1 F(x_k) 
// Ma trận Jacobi là đạo hàm riêng của từng phần tử



// Hệ phương trình
double f1(double x1, double x2) {
    return 4*pow(x1,2) -20*x1+1/4 * pow(x2,2)+8;
}

double f2(double x1, double x2) {
    return 1/2* x1*pow(x2,2) + 2*x1 -5*x2+8;
}

// Đạo hàm riêng
double df1_dx1(double x1, double x2) {
    return 8*x1-20;
}

double df1_dx2(double x1, double x2) {
    return 1/2*x2;
}

double df2_dx1(double x1, double x2) {
    return 1/2*pow(x2,2) + 2;
}

double df2_dx2(double x1, double x2) {
    return x1*x2-5;
}

int main() {
    double x1 = 0.0, x2 = 0.0; // Giá trị khởi tạo
    int max_iter;

    cout << "Nhap so lan lap (max_iter): ";
    cin >> max_iter;

    cout << fixed << setprecision(6);
    cout << "k\t x_k\n";

    for (int k = 0; k < max_iter; ++k) {
        // Tính các giá trị hàm và đạo hàm tại (x1, x2)
        double F1 = f1(x1, x2);
        double F2 = f2(x1, x2);

        double J11 = df1_dx1(x1, x2);
        double J12 = df1_dx2(x1, x2);
        double J21 = df2_dx1(x1, x2);
        double J22 = df2_dx2(x1, x2);

        // Tính định thức Jacobian
        double det = J11 * J22 - J12 * J21;

        if (fabs(det) < 1e-10) {
            cout << "Jacobian suy bien tai buoc lap " << k << ", phuong phap that bai.\n";
            break;
        }

        // Giải hệ tuyến tính J * Δ = -F
        double dx1 = (-F1 * J22 + F2 * J12) / det;
        double dx2 = (-J11 * F2 + J21 * F1) / det;

        // Cập nhật nghiệm
        x1 += dx1;
        x2 += dx2;

        // In nghiệm tại bước k
        cout << k + 1 << "\t (" << x1 << ", " << x2 << ")\n";
    }

    return 0;
}
