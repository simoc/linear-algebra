#include <vector>
#include <initializer_list>
#include <iostream>

/**
 * \brief Simple Matrix class
 *
 * Provides operations on matrices of any dimension.
 */
template<typename T>
class Matrix
{
public:
	Matrix()
	{
	};

	Matrix(const Matrix<T>& matrix)
	{
		if (matrix.isValid())
		{
			m_row_count = matrix.m_row_count;
			m_col_count = matrix.m_col_count;
			m_els = new T[m_row_count * m_col_count];
			for (size_t i = 0;  i < m_row_count * m_col_count; i++)
			{
				m_els[i] = matrix.m_els[i];
			}
		}
	};

	Matrix(std::initializer_list<std::initializer_list<T>> matrix)
	{
		/*
		 * First check that there is at least one row, and all
		 * rows have same number of columns.
		 */
		if (matrix.size() == 0)
			return;

		size_t element_count = 0;
		size_t col_count = 0;
		for (const auto& row : matrix)
		{
			if (row.size() == 0)
				return;

			if (element_count == 0)
				col_count = row.size();
			else if (row.size() != col_count)
				return;
			element_count += row.size();
		}

		m_row_count = matrix.size();
		m_col_count = col_count;
		m_els = new T[element_count];

		/*
		 * Copy elements into array.
		 */
		size_t i = 0;
		for (const auto& row : matrix)
		{
			for (const auto& el : row)
			{
				m_els[i++] = el;
			}
		}
	};

	~Matrix()
	{
		delete []m_els;
	}

	bool isValid() const
	{
		return (m_row_count > 0 && m_col_count > 0);
	}

	Matrix<T> add(const Matrix<T> &matrix)
	{
		if (m_row_count != matrix.m_row_count)
			return Matrix<T>();
		if (m_col_count != matrix.m_col_count)
			return Matrix<T>();

		Matrix<T> added = matrix;
		for (size_t i = 0; i < m_row_count * m_col_count; i++)
		{
			added.m_els[i] = m_els[i] + matrix.m_els[i];
		}
		return added;
	};

	bool isIdentity() const
	{
		if (!isValid())
			return false;

		size_t col = 0;
		for (size_t row = 0; row < m_row_count; row++)
		{
			for (size_t col = 0; col < m_col_count; col++)
			{
				if (row == col && m_els[row * m_col_count + col] != 1)
					return false;
				if (row != col && m_els[row * m_col_count + col] != 0)
					return false;
			}
		}
		return true;
	};

	Matrix<T>& operator=(const Matrix<T>& matrix)
	{
		if (this == &matrix)
			return *this;

		m_row_count = matrix.m_row_count;
		m_col_count = matrix.m_col_count;
		m_els = new T[m_row_count * m_col_count];
		for (size_t i = 0;  i < m_row_count * m_col_count; i++)
		{
			m_els[i] = matrix.m_els[i];
		}
		return *this;
	}

	friend bool operator==(const Matrix<T>& a, const Matrix<T>& b)
	{
		if (a.m_row_count != b.m_row_count)
			return false;
		if (a.m_col_count != b.m_col_count)
			return false;

		for (size_t i = 0; i < a.m_row_count * a.m_col_count; i++)
		{
			if (a.m_els[i] != b.m_els[i])
				return false;
		}
		return true;
	}

	friend std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix)
	{
		for (size_t row = 0; row < matrix.m_row_count; row++)
		{
			os << "[";
			for (size_t col = 0; col < matrix.m_col_count; col++)
			{
				os << matrix.m_els[matrix.m_col_count * row + col] << " ";
			}
			os << "]" << std::endl;
		}
		return os;
	};

private:
	size_t m_row_count = 0;
	size_t m_col_count = 0;
	T *m_els = nullptr;
};

