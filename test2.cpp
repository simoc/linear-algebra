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
		m_dimension3 = Matrix<int>({{11, 2, 13}, {7, 4, 2}, {0, 9, 3}});
		m_missing_column = Matrix<int>({{8, 4, 6}, {16, 9, 7}, {4, 1}});
	}

	void TearDown() override
	{
		std::cout << "TearDown" << std::endl;
	}

	Matrix<int> m_identity;
	Matrix<int> m_zeros;
	Matrix<int> m_dimension3;
	Matrix<int> m_missing_column;
};

TEST_F(MatrixTester, IsIdentity)
{
  EXPECT_TRUE(m_identity.isIdentity());
  EXPECT_FALSE(m_zeros.isIdentity());
}

TEST_F(MatrixTester, IsValid)
{
  EXPECT_TRUE(m_identity.isValid());
  EXPECT_FALSE(m_missing_column.isValid());
  EXPECT_FALSE(m_identity.add(m_dimension3).isValid());
}
