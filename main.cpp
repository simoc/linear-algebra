#include <iostream>
#include "matrix.h"

int
main(int argc, char *argv[])
{
	Matrix<int> m1({{1, 0}, {0, 1}});
	Matrix<int> m2({{7, 8}, {19, 23}});
	Matrix<int> m3 = m1.add(m2);

	std::cout << m1 << std::endl;
	std::cout << std::endl;
	std::cout << m2 << std::endl;
	std::cout << std::endl;
	std::cout << m3 << std::endl;
	std::cout << (m2 == m2) << std::endl;
	std::cout << (m1 == m2) << std::endl;
}

