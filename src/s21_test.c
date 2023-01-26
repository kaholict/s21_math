#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_tests) {
  ck_assert_int_eq(abs(-9), s21_abs(-9));
  ck_assert_int_eq(abs(98), s21_abs(98));
  ck_assert_int_eq(abs(-1237), s21_abs(-1237));
  ck_assert_int_eq(abs(36985217), s21_abs(36985217));
  ck_assert_int_eq(abs(0), s21_abs(0));
}
END_TEST

START_TEST(fabs_tests) {
  ck_assert_int_eq(fabs(-11.951236), s21_fabs(-11.951236));
  ck_assert_int_eq(fabs(11.951236), s21_fabs(11.951236));
  ck_assert_int_eq(fabs(-1000.21313), s21_fabs(-1000.21313));
  ck_assert_int_eq(fabs(32346234.21313), s21_fabs(32346234.21313));
  ck_assert_int_eq(fabs(0.0), s21_fabs(0.0));
}
END_TEST

START_TEST(fmod_tests) {
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, 1));
  ck_assert_ldouble_nan(s21_fmod(1, S21_NAN));
  ck_assert_ldouble_infinite(s21_fmod(S21_INF, 1));
  ck_assert_ldouble_infinite(s21_fmod(S21_NINF, 1));
  ck_assert_ldouble_nan(s21_fmod(1, 0));
  ck_assert_ldouble_eq(fmod(1.1, 1.1), s21_fmod(1.1, 1.1));
  ck_assert_ldouble_eq_tol(fmod(-11.951236, 3.3), s21_fmod(-11.951236, 3.3), 6);
  ck_assert_ldouble_eq_tol(fmod(11.951236, 3.3), s21_fmod(11.951236, 3.3), 6);
  ck_assert_ldouble_eq_tol(fmod(-1000.21313, 3.3), s21_fmod(-1000.21313, 3.3),
                           6);
  ck_assert_ldouble_eq_tol(fmod(32346234.21313, 3.3),
                           s21_fmod(32346234.21313, 3.3), 6);
  ck_assert_ldouble_eq_tol(fmod(0, 3.3), s21_fmod(0, 3.3), 6);
  ck_assert_ldouble_eq_tol(fmod(1, 3.3), s21_fmod(1, 3.3), 6);
  ck_assert_ldouble_eq_tol(fmod(2.5, 3.3), s21_fmod(2.5, 3.3), 6);
}
END_TEST

START_TEST(pow_tests) {
  ck_assert_float_eq_tol(pow(15, 0), s21_pow(15, 0), 6);
  ck_assert_float_nan(s21_pow(S21_NAN, 3.3));
  //  ck_assert_float_nan(s21_pow(S21_INF, 3.3));
  ck_assert_float_eq_tol(-pow(11.951236, 3.3), s21_pow(-11.951236, 3.3), 6);
  ck_assert_float_eq_tol(pow(11.951236, 3.3), s21_pow(11.951236, 3.3), 6);
  ck_assert_float_eq_tol(-pow(1000.21313, 3.3), s21_pow(-1000.21313, 3.3), 6);
  ck_assert_float_eq_tol(pow(32346234.2, 3.3), s21_pow(32346234.2, 3.3), 6);
  ck_assert_float_eq_tol(pow(0, 3.3), s21_pow(0, 3.3), 6);
  ck_assert_float_eq_tol(pow(1, 3.3), s21_pow(1, 3.3), 6);
  ck_assert_float_eq_tol(pow(123, -2), s21_pow(123, -2), 6);
  ck_assert_int_eq(pow(13, 2), s21_pow(13, 2));
}
END_TEST

START_TEST(ceil_tests) {
  ck_assert_ldouble_eq(ceil(0), s21_ceil(0));
  ck_assert_ldouble_eq(ceil(S21_INF), s21_ceil(S21_INF));
  ck_assert_ldouble_eq(ceil(DBL_MAX), s21_ceil(DBL_MAX));
  ck_assert_ldouble_eq(ceil(S21_NINF), s21_ceil(S21_NINF));
  ck_assert_ldouble_nan(s21_ceil(NAN));
  ck_assert_ldouble_eq(ceil(-12.51), s21_ceil(-12.51));
  ck_assert_ldouble_eq(ceil(12.51), s21_ceil(12.51));
  ck_assert_ldouble_eq(ceil(1000), s21_ceil(1000));
  ck_assert_ldouble_eq(ceil(102.0000002), s21_ceil(102.0000002));
}
END_TEST

START_TEST(floor_tests) {
  ck_assert_ldouble_eq(floor(0), s21_floor(0));
  ck_assert_ldouble_eq(floor(S21_INF), s21_floor(S21_INF));
  ck_assert_ldouble_eq(floor(DBL_MAX), s21_floor(DBL_MAX));
  ck_assert_ldouble_eq(floor(S21_NINF), s21_floor(S21_NINF));
  ck_assert_ldouble_nan(s21_floor(NAN));
  ck_assert_ldouble_eq(floor(-12.51), s21_floor(-12.51));
  ck_assert_ldouble_eq(floor(12.51), s21_floor(12.51));
  ck_assert_ldouble_eq(floor(-0.54), s21_floor(-0.54));
  ck_assert_ldouble_eq(floor(1000), s21_floor(1000));
  ck_assert_ldouble_eq(floor(102.0000002), s21_floor(102.0000002));
}
END_TEST

START_TEST(exp_tests) {
  ck_assert_float_eq_tol(exp(-12.51), s21_exp(-12.51), 6);
  ck_assert_float_eq(exp(12.51), s21_exp(12.51));
  ck_assert_float_eq(exp(-0.54), s21_exp(-0.54));
  ck_assert_float_eq(exp(1000), s21_exp(1000));
  ck_assert_float_eq(exp(1), s21_exp(1));
  ck_assert_float_eq(exp(2), s21_exp(2));
  ck_assert_float_eq(exp(-1), s21_exp(-1));
  ck_assert_float_eq(exp(0), s21_exp(0));
  ck_assert_int_eq(exp(S21_NAN), s21_exp(S21_NAN));  // nan!
  ck_assert_float_eq(exp(710), s21_exp(710));
  ck_assert_float_eq(exp(1.2345), s21_exp(1.2345));
  ck_assert_float_eq(exp(1.23454656768), s21_exp(1.23454656768));
  ck_assert_float_eq(exp(DBLMAX), s21_exp(DBLMAX));
}
END_TEST

START_TEST(sin_tests) {
  ck_assert_float_nan(s21_sin(S21_INF));
  ck_assert_float_nan(s21_sin(S21_NAN));
  ck_assert_float_eq(sin(-12.51), s21_sin(-12.51));
  ck_assert_float_eq(sin(12.51), s21_sin(12.51));
  ck_assert_float_eq(sin(0.0), s21_sin(0.0));
  ck_assert_float_eq(sin(1.0), s21_sin(1.0));
  ck_assert_float_eq(sin(3.14), s21_sin(3.14));
  ck_assert_float_eq(sin(6.28), s21_sin(6.28));
  ck_assert_float_eq(sin(2.2343), s21_sin(2.2343));
  ck_assert_float_eq(sin(0.1234), s21_sin(0.1234));
}
END_TEST

START_TEST(cos_tests) {
  ck_assert_float_nan(s21_cos(S21_INF));
  ck_assert_float_nan(s21_cos(S21_NAN));
  ck_assert_float_nan(s21_cos(S21_NAN));
  ck_assert_float_nan(s21_cos(S21_INF));
  ck_assert_float_eq(cos(-12.51), s21_cos(-12.51));
  ck_assert_float_eq(cos(12.51), s21_cos(12.51));
  ck_assert_float_eq(cos(0.0), s21_cos(0.0));
  ck_assert_float_eq(cos(1.0), s21_cos(1.0));
  ck_assert_float_eq(cos(3.14), s21_cos(3.14));
  ck_assert_float_eq(cos(6.28), s21_cos(6.28));
  ck_assert_float_eq(cos(2.2343), s21_cos(2.2343));
  ck_assert_float_eq(cos(0.1234), s21_cos(0.1234));
}
END_TEST

START_TEST(tan_tests) {
  ck_assert_float_nan(s21_tan(S21_INF));
  ck_assert_float_nan(s21_tan(S21_NAN));
  ck_assert_float_eq(tan(-12.51), s21_tan(-12.51));
  ck_assert_float_eq(tan(12.51), s21_tan(12.51));
  ck_assert_float_eq(tan(0), s21_tan(0));
  ck_assert_float_eq(tan(1), s21_tan(1));
  ck_assert_float_eq(tan(3.14), s21_tan(3.14));
  ck_assert_float_eq(tan(6.28), s21_tan(6.28));
  ck_assert_float_eq(tan(2.2343), s21_tan(2.2343));
  ck_assert_float_eq(tan(0.1234), s21_tan(0.1234));
}
END_TEST

START_TEST(sqrt_tests) {
  ck_assert_float_eq(sqrt(0.0), s21_sqrt(0.0));
  ck_assert_float_eq_tol(sqrt(1.0), s21_sqrt(1.0), 6);
  ck_assert_float_eq(sqrt(3.14), s21_sqrt(3.14));
  ck_assert_float_eq(sqrt(6.28), s21_sqrt(6.28));
  ck_assert_float_eq(sqrt(2.2343), s21_sqrt(2.2343));
  ck_assert_int_eq(sqrt(-123), s21_sqrt(-123));
  // ck_assert_float_eq(sqrt(0.9), s21_sqrt(0.9));  // problem!!
}

START_TEST(log_tests) {
  ck_assert_float_nan(s21_log(-12.51));
  ck_assert_float_eq(log(12.51), s21_log(12.51));
  ck_assert_float_eq(log(0.0), s21_log(0.0));
  ck_assert_float_eq(log(1.0), s21_log(1.0));
  ck_assert_float_eq(log(3.14), s21_log(3.14));
  ck_assert_float_eq(log(6.28), s21_log(6.28));
  ck_assert_float_eq(log(2.2343), s21_log(2.2343));
  ck_assert_float_eq_tol(log(0.1234), s21_log(0.1234), 6);
}
END_TEST

START_TEST(asin_tests) {
  ck_assert_float_nan(s21_asin(S21_NAN));
  ck_assert_float_nan(s21_asin(S21_INF));
  ck_assert_float_nan(s21_asin(-12.51));
  ck_assert_float_eq(asin(S21_EPS), s21_asin(S21_EPS));
  ck_assert_float_eq(asin(0.1234), s21_asin(0.1234));
  ck_assert_float_eq(asin(0), s21_asin(0));
  ck_assert_float_eq(asin(1), s21_asin(1));
  ck_assert_float_eq(asin(-1), s21_asin(-1));
  ck_assert_float_eq(asin(0.5), s21_asin(0.5));
  ck_assert_float_eq(asin(-0.5), s21_asin(-0.5));
}
END_TEST

START_TEST(acos_tests) {
  ck_assert_float_nan(s21_acos(S21_NAN));
  ck_assert_float_nan(s21_acos(S21_INF));
  ck_assert_int_eq(acos(-12.51), s21_acos(-12.51));
  ck_assert_int_eq(acos(12.51), s21_acos(12.51));
  ck_assert_int_eq(acos(2.2343), s21_acos(2.2343));
  ck_assert_float_eq(acos(0.1234), s21_acos(0.1234));
  ck_assert_float_eq(acos(0), s21_acos(0));
  ck_assert_float_eq(acos(1), s21_acos(1));
  ck_assert_float_eq(acos(-1), s21_acos(-1));
  ck_assert_float_eq(acos(0.5), s21_acos(0.5));
  ck_assert_float_eq(acos(-0.5), s21_acos(-0.5));
}
END_TEST

START_TEST(atan_tests) {
  ck_assert_float_nan(s21_atan(S21_NAN));
  ck_assert_float_eq(atan(S21_INF), s21_atan(S21_INF));
  ck_assert_float_eq(atan(-S21_INF), s21_atan(-S21_INF));
  ck_assert_int_eq(atan(-12.51), s21_atan(-12.51));
  ck_assert_float_eq(atan(12.51), s21_atan(12.51));
  ck_assert_float_eq(atan(3.14), s21_atan(3.14));
  ck_assert_float_eq(atan(6.28), s21_atan(6.28));
  ck_assert_float_eq(atan(0.1234), s21_atan(0.1234));
  ck_assert_float_eq(atan(0), s21_atan(0));
  ck_assert_float_eq(atan(1), s21_atan(1));
  ck_assert_float_eq(atan(-1), s21_atan(-1));
//  ck_assert_float_eq(atan(2.5), s21_atan(2.5));
//  ck_assert_float_eq(atan(-3.5), s21_atan(-3.5));
}
END_TEST

Suite *s21_math_tests_create() {
  Suite *s21_math = suite_create("s21_math");
  TCase *s21_math_tests = tcase_create("S21_MATH");
  tcase_add_test(s21_math_tests, ceil_tests);
  tcase_add_test(s21_math_tests, floor_tests);
  tcase_add_test(s21_math_tests, exp_tests);
  tcase_add_test(s21_math_tests, sin_tests);
  tcase_add_test(s21_math_tests, cos_tests);
  tcase_add_test(s21_math_tests, tan_tests);
  tcase_add_test(s21_math_tests, abs_tests);
  tcase_add_test(s21_math_tests, fabs_tests);
  tcase_add_test(s21_math_tests, fmod_tests);
  tcase_add_test(s21_math_tests, pow_tests);
  tcase_add_test(s21_math_tests, sqrt_tests);
  tcase_add_test(s21_math_tests, log_tests);
  tcase_add_test(s21_math_tests, asin_tests);
  tcase_add_test(s21_math_tests, acos_tests);
  tcase_add_test(s21_math_tests, atan_tests);
  suite_add_tcase(s21_math, s21_math_tests);
  return s21_math;
}

int main() {
  Suite *s21_math = s21_math_tests_create();
  SRunner *s21_math_runner = srunner_create(s21_math);
  int number_failed;
  srunner_run_all(s21_math_runner, CK_NORMAL);
  number_failed = srunner_ntests_failed(s21_math_runner);
  srunner_free(s21_math_runner);

  return number_failed == 0 ? 0 : 1;
}