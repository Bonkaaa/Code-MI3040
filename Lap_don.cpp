#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Điều kiện phương pháp lặp đơn
// - Khoàng phân ly nghiệm
// - Chọn phi(x) sao cho q = max |đạo hàm của phi(x)| < 1 trên khoảng phân ly nghiệm
// - Thiếp lập điều kiện dừng: |x_n-x_n-1| <= (q*epsilon)/(1-q)
// x_n = phi(x_n-1)



// Hàm g(x) duơc dinh nghia theo phuong trinh x = g(x)
double g(double x) {
    return cbrt(1-3*pow(x,2));
}

int main() {
    double x0, error;
    int max_iter;
    
    cout << "Nhap gia tri ban dau x0: ";
    cin >> x0;
    cout << "Nhap error: ";
    cin >> error;
    cout << "Nhap so lan lap toi da: ";
    cin >> max_iter;
    
    cout << fixed << setprecision(10);
    cout << "----------------------------------------------------\n";
    cout << "| n  |   x_(n-1)   |     x_n     | |x_n - x_(n-1)| |\n";
    cout << "----------------------------------------------------\n";
    
    double x_prev = x0, x_next;
    int iter = 0;
    
    do {
        x_next = g(x_prev);
        cout << "| " << setw(2) << iter + 1 << " | " << setw(10) << x_prev
             << " | " << setw(10) << x_next
             << " | " << setw(10) << fabs(x_next - x_prev) << " |\n";
        
        if (fabs(x_next - x_prev) < error) {
            cout << "----------------------------------------------------\n";
            cout << "Nghiem gan dung la: " << x_next << " sau " << iter + 1 << " lan lap.\n";
            return 0;
        }
        
        x_prev = x_next;
        iter++;
    } while (iter < max_iter);
    
    cout << "----------------------------------------------------\n";
    cout << "Kh�ng h?i t? sau " << max_iter << " l?n l?p.\n";
    
    return 0;
}
