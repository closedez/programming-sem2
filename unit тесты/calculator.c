// calculator.c - чужой код, который мы тестируем

#include <math.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

double divide(int a, int b) {
    if (b == 0) {
        return 0;  // ошибка: возвращает 0 при делении на ноль (потенциальный баг)
    }
    return (double)a / b;
}

int factorial(int n) {
    if (n < 0) return -1;  // ошибка для отрицательных чисел
    if (n == 0 || n == 1) return 1;
    int result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int is_prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}