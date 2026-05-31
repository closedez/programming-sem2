// test_calculator.c
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include "calculator.h"
#include <math.h>

// Тест сложения
static void test_add(void **state) {
    (void)state;
    assert_int_equal(add(2, 3), 5);
    assert_int_equal(add(-1, 1), 0);
    assert_int_equal(add(0, 0), 0);
    assert_int_equal(add(-5, -3), -8);
}

// Тест вычитания
static void test_subtract(void **state) {
    (void)state;
    assert_int_equal(subtract(5, 3), 2);
    assert_int_equal(subtract(0, 5), -5);
    assert_int_equal(subtract(-2, -3), 1);
}

// Тест умножения
static void test_multiply(void **state) {
    (void)state;
    assert_int_equal(multiply(4, 3), 12);
    assert_int_equal(multiply(0, 5), 0);
    assert_int_equal(multiply(-2, 3), -6);
}

// Тест деления
static void test_divide(void **state) {
    (void)state;
    assert_float_equal(divide(10, 2), 5.0, 0.0001);
    assert_float_equal(divide(7, 2), 3.5, 0.0001);
    assert_float_equal(divide(5, 0), 0.0, 0.0001);  // известный баг
}

// Тест факториала
static void test_factorial(void **state) {
    (void)state;
    assert_int_equal(factorial(0), 1);
    assert_int_equal(factorial(1), 1);
    assert_int_equal(factorial(5), 120);
    assert_int_equal(factorial(-3), -1);  // ошибка для отрицательных
}

// Тест простых чисел
static void test_is_prime(void **state) {
    (void)state;
    assert_int_equal(is_prime(2), 1);
    assert_int_equal(is_prime(3), 1);
    assert_int_equal(is_prime(4), 0);
    assert_int_equal(is_prime(17), 1);
    assert_int_equal(is_prime(1), 0);
    assert_int_equal(is_prime(0), 0);
}

int main(void) {
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_add),
        cmocka_unit_test(test_subtract),
        cmocka_unit_test(test_multiply),
        cmocka_unit_test(test_divide),
        cmocka_unit_test(test_factorial),
        cmocka_unit_test(test_is_prime),
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}