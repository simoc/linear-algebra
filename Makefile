all: la gtest-la

la: main.cpp matrix.h
	gcc -Wall -g -std=c++11 -o la main.cpp -lstdc++

gtest-la: test1.cpp test2.cpp matrix.h
	gcc -Wall -g -std=c++11 -o gtest-la test1.cpp test2.cpp \
	-I${GOOGLETESTDIR}/googletest/include \
	${GOOGLETESTDIR}/lib/libgtest.a \
	-lpthread \
	${GOOGLETESTDIR}/lib/libgtest_main.a -lstdc++

