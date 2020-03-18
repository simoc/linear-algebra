#include "gtest/gtest.h"
#include "matrix.h"

/**
 * Test that a matrix is equal to itself.
 */
TEST(MatrixTest, EqualsItself)
{
  Matrix<int> m1({{4, 9}, {1, 7}});

  EXPECT_EQ(m1, m1);
}

/**
 * Test that adding a zero matrix is equal to original matrix.
 */
TEST(MatrixTest, AddZero)
{
  Matrix<int> m1({{4, 9}, {1, 7}});
  Matrix<int> zero({{0, 0}, {0, 0}});
  Matrix<int> added = m1.add(zero);

  EXPECT_EQ(added, m1);
}

/**
 * Test that A + B is the same as B + A.
 */
TEST(MatrixTest, AddCommutative)
{
  Matrix<int> m1({{4, 9}, {1, 7}});
  Matrix<int> m2({{13, 2}, {7, 6}});

  Matrix<int> m3 = m1.add(m2);
  Matrix<int> m4 = m2.add(m1);

  EXPECT_EQ(m3, m4);
}
