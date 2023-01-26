CC = gcc
TESTFLAGS = -lcheck
GCCFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage
SRCS = s21_math.c
TEST_FILE = s21_test.c

all: s21_math.a test gcovreport

s21_math.a: clean
	$(CC) $(GCCFLAGS) -std=c11 -c $(SRCS)
	ar rc s21_math.a *.o


#gcov_report: s21_math.a
#	gcc $(GCCFLAGS) $(GCOVFLAGS) $(TEST_FILE) $(TESTFLAGS) $(SRCS) -o gcovreport
#	./gcovreport
#	lcov -t "gcovreport" -o gcovreport.info -c -d .
#	genhtml -o report gcovreport.info
#	rm -rf gcovreport gcovreport.info *.gcda *.gcno math_test.gcda math_test.gcno
#	gcc $(GCCFLAGS) $(GCOVFLAGS) $(TEST_FILE) $(TESTFLAGS) $(SRCS) -o math_test
#	./math_test
#	lcov -t "./gcov" -o report.info --no-external -c -d .
#	genhtml -o report report.info
#	open ./report/index.html

test: s21_math.a
	gcc $(GCCFLAGS) $(GCOVFLAGS) $(TEST_FILE) $(TESTFLAGS) $(SRCS) -o math_test
	./math_test

gcovreport: test
	lcov -t "./gcov" -o report.info --no-external -c -d .
	genhtml -o report report.info
	open ./report/index.html

clean:
	rm -rf *.o *.a *.out *.gcno *.gcda *.info *.gch math_test report gcovreport