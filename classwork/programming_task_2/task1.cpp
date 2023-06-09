#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Matrix
{
public:
    Matrix(int rows, int columns) : rows_(rows), columns_(columns), data_(rows * columns) {}

    template <typename U>
    Matrix(const std::initializer_list<std::initializer_list<U>> &elements) : Matrix(elements.size(), elements.begin()->size())
    {
        int i = 0;
        for (const auto &row : elements)
        {
            if (row.size() != columns_)
            {
                throw std::invalid_argument("Invalid number of columns in initializer list.");
            }
            for (const auto &element : row)
            {
                data_[i++] = static_cast<T>(element);
            }
        }
    }

    int rows() const { return rows_; }
    int columns() const { return columns_; }
    std::vector<T> &data() { return data_; }

    template <typename U>
    Matrix operator+(const Matrix<U> &other) const
    {
        if (rows_ != other.rows_ || columns_ != other.columns_)
        {
            throw std::invalid_argument("Matrix dimensions don't match for addition.");
        }

        Matrix result(rows_, columns_);
        for (int i = 0; i < rows_ * columns_; ++i)
        {
            result.data_[i] = data_[i] + other.data_[i];
        }
        return result;
    }

    template <typename U>
    Matrix operator-(const Matrix<U> &other) const
    {
        if (rows_ != other.rows_ || columns_ != other.columns_)
        {
            throw std::invalid_argument("Matrix dimensions don't match for subtraction.");
        }

        Matrix result(rows_, columns_);
        for (int i = 0; i < rows_ * columns_; ++i)
        {
            result.data_[i] = data_[i] - other.data_[i];
        }
        return result;
    }

    template <typename U, typename = std::enable_if_t<std::is_same_v<T, U>>>
    Matrix operator*(const Matrix<U> &other) const
    {
        static_assert(std::is_same_v<T, U>, "Matrix types must be the same for multiplication.");
        static_assert(std::is_arithmetic_v<T>, "Matrix types must be arithmetic for multiplication.");

        if (columns_ != other.rows_)
        {
            throw std::invalid_argument("Matrix dimensions don't match for multiplication.");
        }

        Matrix result(rows_, other.columns_);
        for (int i = 0; i < rows_; ++i)
        {
            for (int j = 0; j < other.columns_; ++j)
            {
                T sum = 0;
                for (int k = 0; k < columns_; ++k)
                {
                    sum += data_[i * columns_ + k] * other.data_[k * other.columns_ + j];
                }
                result.data_[i * other.columns_ + j] = sum;
            }
        }
        return result;
    }

    template <typename U>
    friend std::ostream &operator<<(std::ostream &os, const Matrix<U> &matrix);

private:
    int rows_;
    int columns_;
    std::vector<T> data_;
};

template <typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &matrix)
{
    for (int i = 0; i < matrix.rows_; ++i)
    {
        for (int j = 0; j < matrix.columns_; ++j)
        {
            os << matrix.data_[i * matrix.columns_ + j] << ' ';
        }
        os << '\n';
    }
    return os;
}

template <typename T>
Matrix<T> transpose(Matrix<T> matrix)
{
    Matrix<T> result(matrix.columns(), matrix.rows());
    for (int i = 0; i < matrix.rows(); ++i)
    {
        for (int j = 0; j < matrix.columns(); ++j)
        {
            result.data()[j * result.columns() + i] = matrix.data()[i * matrix.columns() + j];
        }
    }
    return result;
}

template <typename T>
Matrix<T> multiplyByScalar(Matrix<T> matrix, T scalar)
{
    for (int i = 0; i < matrix.rows(); ++i)
    {
        for (int j = 0; j < matrix.columns(); ++j)
        {
            matrix.data()[i * matrix.columns() + j] = matrix.data()[i * matrix.columns() + j] * scalar;
        }
    }
    return matrix;
}

int main()
{
    try
    {
        Matrix<int> matrix1(2, 3);
        matrix1 = {{1, 2, 3},
                   {4, 5, 6}};

        Matrix<int> matrix2(2, 3);
        matrix2 = {{7, 8, 9},
                   {9, 10, 12}};

        Matrix<int> matrix3(3, 3);
        matrix3 = {{7, 8, 9},
                   {8, 10, 12},
                   {47, 11, 19}};

        Matrix<int> matrix4(3, 3);
        matrix4 = {{6, 9, 10},
                   {9, 10, 12},
                   {7, 11, 19}};

        Matrix<int> matrix5 = matrix1 + matrix2;
        std::cout << "matrix1 + matrix2:\n"
                  << matrix5 << '\n';

        Matrix<int> matrix6 = matrix1 - matrix2;
        std::cout << "matrix1 - matrix2:\n"
                  << matrix6 << '\n';

        Matrix<int> matrix7 = matrix3 * matrix4;
        std::cout << "matrix3 * matrix4:\n"
                  << matrix7 << '\n';

        Matrix<int> matrix8 = transpose(std::move(matrix1));
        std::cout << "Transposed matrix1:\n"
                  << matrix8 << '\n';

        Matrix<int> matrix9 = multiplyByScalar(std::move(matrix2), 2);
        std::cout << "matrix2 multiplied by 2:\n"
                  << matrix9 << '\n';
        Matrix<int> matrix10 = matrix1 + matrix3;
        std::cout << "matrix1 + matrix3:\n"
                  << matrix3 << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception occurred: " << e.what() << '\n';
    }

    try
    {
        int rows, columns;

        std::cout << "Enter the number of rows: \n";
        std::cin >> rows;

        std::cout << "Enter the number of columns: \n";
        std::cin >> columns;

        Matrix<int> matrix11(rows, columns);
        std::cout << "Enter the elements of matrix1:\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                std::cin >> matrix11.data()[i * columns + j];
            }
        }
        std::cout << "matrix1:\n"
                  << matrix11 << '\n';

        std::cout << "Enter the number of rows of the second Matrix: \n";
        std::cin >> rows;

        std::cout << "Enter the number of columns the second Matrix: \n";
        std::cin >> columns;

        Matrix<int> matrix12(rows, columns);
        std::cout << "Enter the elements of the second Matrix\n";
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                std::cin >> matrix12.data()[i * columns + j];
            }
        }
        std::cout << "matrix2:\n"
                  << matrix12 << '\n';

        try
        {

            Matrix<int> matrix13 = matrix11 + matrix12;
            std::cout << "matrix1 + matrix2:\n"
                      << matrix13 << '\n';

            Matrix<int> matrix14 = matrix11 - matrix12;
            std::cout << "matrix1 - matrix2:\n"
                      << matrix14 << '\n';

            Matrix<int> matrix16 = transpose(std::move(matrix11));
            std::cout << "Transposed matrix1:\n"
                      << matrix16 << '\n';

            Matrix<int> matrix17 = multiplyByScalar(std::move(matrix12), 2);
            std::cout << "matrix2 multiplied by 2:\n"
                      << matrix17 << '\n';

            Matrix<int> matrix15 = matrix11 * matrix12;
            std::cout << "matrix1 * matrix2:\n"
                      << matrix15 << '\n';
        }
        catch (const std::exception &e)
        {
            std::cout << "Exception occurred: " << e.what() << '\n';
        }
    }
    catch (const std::exception &e)
    {
        std::cout << "Exception occurred: " << e.what() << '\n';
    }

    return 0;
}
