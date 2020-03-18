#include <vector>
#include <initializer_list>
#include <iostream>

/**
 * Simple Matrix class
 */
template<typename T>
class Matrix
{
public:
	Matrix()
	{
	};

	Matrix(std::initializer_list<std::initializer_list<T>> matrix)
	{
		for (const auto& row : matrix)
		{
			m_els.push_back(row);
		}
	};

	Matrix<T> add(const Matrix<T> &b)
	{
		Matrix<T> matrix;

		typename std::vector<std::vector<T>>::const_iterator it1 = m_els.cbegin();
		typename std::vector<std::vector<T>>::const_iterator it2 = b.m_els.cbegin();
		while (it1 != m_els.cend() && it2 != b.m_els.cend())
		{
			std::vector<T> row1 = *it1;
			std::vector<T> row2 = *it2;

			std::vector<T> new_row;

			typename std::vector<T>::const_iterator it3 = row1.cbegin();
			typename std::vector<T>::const_iterator it4 = row2.cbegin();
			while (it3 != row1.cend() && it4 != row2.cend())
			{
				new_row.push_back(*it3 + *it4);

				++it3;
				++it4;
			}
			matrix.m_els.push_back(new_row);

			++it1;
			++it2;
		}

		return matrix;
	};

	bool isIdentity() const
	{
		int column = 0;
		typename std::vector<std::vector<T>>::const_iterator it1 = m_els.cbegin();
		while (it1 != m_els.cend())
		{
			std::vector<T> row = *it1;
			for (int i = 0; i < row.size(); i++)
			{
				if (i == column && row[i] != 1)
					return false;
				if (i != column && row[i] != 0)
					return false;
			}
			++it1;
			column++;
		}

		return true;
	};

	friend bool operator==(const Matrix<T>& a, const Matrix<T>& b)
	{
		typename std::vector<std::vector<T>>::const_iterator it1 = a.m_els.cbegin();
		typename std::vector<std::vector<T>>::const_iterator it2 = b.m_els.cbegin();
		while (it1 != a.m_els.cend() && it2 != b.m_els.cend())
		{
			if (*it1 != *it2)
				return false;

			++it1;
			++it2;
		}
		return true;
	}

	friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
	{
		for (const auto& row : matrix.m_els)
		{
			os << "[";
			for (const auto& el : row)
			{
				os << el << " ";
			}
			os << "]" << std::endl;
		}
		return os;
	};

private:
	std::vector<std::vector<T>> m_els;
};

