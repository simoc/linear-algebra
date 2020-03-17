#include "gtest/gtest.h"
#include "matrix.h"

TEST(MatrixTest, EqualsItself)
{
  Matrix<int> m1({{4, 9}, {1, 7}});

  EXPECT_EQ(m1, m1);
}

TEST(MatrixTest, AddZero)
{
  Matrix<int> m1({{4, 9}, {1, 7}});
  Matrix<int> zero({{0, 0}, {0, 0}});
  Matrix<int> added = m1.add(zero);

  EXPECT_EQ(added, m1);
}
