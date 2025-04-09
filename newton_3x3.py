import numpy as np

def F(x):
    x1, x2, x3 = x
    return np.array([
        x1**2 + x2**2 + x3**2 - 3,
        x1 + x2 - x3,
        x1 * x2 * x3 - 1
    ])

def J(x):
    x1, x2, x3 = x
    return np.array([
        [2*x1,     2*x2,     2*x3],
        [1,        1,       -1   ],
        [x2*x3,    x1*x3,    x1*x2]
    ])

x = np.array([1.0, 0.5, 1.5])  # Đổi điểm khởi đầu
max_iter = int(input("Nhập số lần lặp: "))
print("k\t x_k = (x1_k, x2_k, x3_k)")

for k in range(1, max_iter + 1):
    Fx = F(x)
    Jx = J(x)

    # Kiểm tra Jacobian khả nghịch
    if abs(np.linalg.det(Jx)) < 1e-10:
        print(f"Jacobian suy biến tại bước {k}. Dừng lại.")
        break

    delta = np.linalg.solve(Jx, -Fx)
    x = x + delta

    print(f"{k}\t x_k = ({x[0]}, {x[1]}, {x[2]})")
