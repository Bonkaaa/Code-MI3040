import numpy as np

# F(X)
def F(X):
    x1, x2, x3 = X
    return np.array([
        [3*x1 - np.cos(x2*x3) - 0.5],  # f1(x1, x2, x3)
        [x1**2 - 81*(x2 + 0.1)**2 + np.sin(x3) + 1.06],  # f2(x1, x2, x3)
        [np.exp(-x1*x2) + 20*x3 + 9.1389]  # f3(x1, x2, x3)
    ])

# Jacobian
def J(X):
    x1, x2, x3 = X
    return np.array([
        [3, x3 * np.sin(x2*x3), x2 * np.sin(x2*x3)],  # Đạo hàm của f1 theo x1, x2, x3
        [2*x1, -162*(x2 + 0.1), np.cos(x3)],  # Đạo hàm của f2 theo x1, x2, x3
        [-x2 * np.exp(-x1*x2), -x1 * np.exp(-x1*x2), 20]   # Đạo hàm của f3 theo x1, x2, x3
    ])

# Newton Modified
def newton_method_modified(initial_guess, max_iterations=20, tol=1e-6):
    X = initial_guess
    J_X0 = J(initial_guess)  # Tính Jacobian ban đầu J(X0)
    
    for i in range(max_iterations):
        F_X = F(X)
        
        # Giải phương trình J(X0) * delta = -F(X)
        try:
            delta = np.linalg.solve(J_X0, -F_X.flatten())  # Giải hệ phương trình
        except np.linalg.LinAlgError:
            print(f"Lỗi khi giải phương trình tại bước {i+1}.")
            return None
        
        # Cập nhật giá trị X
        X = X + delta
        
        # In nghiệm của từng bước lặp
        print(f"Iteration {i+1}: x1 = {X[0]}, x2 = {X[1]}, x3 = {X[2]}")
        
        # Kiểm tra điều kiện dừng
        if np.linalg.norm(delta) < tol:
            print(f'Đã hội tụ sau {i+1} bước lặp.')
            return X
    
    print('Không hội tụ sau số bước lặp tối đa.')
    return X

initial_guess = np.array([0.49, 0, -0.5])

# Chạy phương pháp Newton Modified
bucac = newton_method_modified(initial_guess)

if bucac is not None:
    print(f'Nghiệm tìm được: x1 = {bucac[0]}, x2 = {bucac[1]}, x3 = {bucac[2]}')
