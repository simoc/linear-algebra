#include <iostream>
#include "matrix.h"
#include "gtest/gtest.h"

class MatrixTester : public ::testing::Test
{
protected:
	void SetUp() override
	{
		std::cout << "SetUp" << std::endl;
		m_identity = Matrix<int>({{1, 0}, {0, 1}});
		m_zeros = Matrix<int>({{0, 0}, {0, 0}});
	}

	void TearDown() override
	{
		std::cout << "TearDown" << std::endl;
	}

	Matrix<int> m_identity;
	Matrix<int> m_zeros;
};

TEST_F(MatrixTester, IsIdentity)
{
  EXPECT_TRUE(m_identity.isIdentity());
  EXPECT_FALSE(m_zeros.isIdentity());
}

