all: la gtest-la

la: main.cpp matrix.h
	gcc -g -std=c++11 -o la main.cpp -lstdc++

gtest-la: test1.cpp matrix.h
	gcc -g -std=c++11 -o gtest-la test1.cpp \
	-I${GOOGLETESTDIR}/include \
	${GOOGLETESTDIR}/lib/libgtest.a \
	-lpthread \
	${GOOGLETESTDIR}/lib/libgtest_main.a -lstdc++

