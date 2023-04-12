#include <iostream>

using namespace std;

template<typename T, int N, int M>
class Matrix {
public:
    T matrix[N][M] = { 0 };

    Matrix() = default;

    // оператор +=
    Matrix& operator +=(const Matrix& other) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matrix[i][j] += other.matrix[i][j];
            }
        }
        return *this;
    }

    //оператор "+"
    Matrix operator +(const Matrix& other)
    {
        Matrix newStr = *this;
        newStr += other;
        return newStr;
    }

    // оператор *
    template<int U, int V>
    Matrix<T, N, V> operator *(const Matrix<T, U, V>& other) {
        Matrix<T, N, V> newMatrix;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < V; j++) {
                for (int k = 0; k < M; k++) {
                    newMatrix.matrix[i][j] += (matrix[i][k] * other.matrix[k][j]);
                }
            }
        }
        return newMatrix;
    }

    // оператор ++ (префиксный)
    Matrix& operator ++() {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < M; ++j)
                ++matrix[i][j];
        return *this;
    }

    // оператор ++ (постфиксный)
    Matrix operator ++(T) {
        Matrix newMatrix = *this;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                matrix[i][j]++;
        return newMatrix;
    }

    // оператор чтения и изменения элемента по индексу 
    T* operator [](T index)
    {
        return matrix[index];
    }

    // метод чтения и изменения элемента по индексу
    T& el(T r, T c) {
        return matrix[r][c];
    }

    // метод вычисления определителя (крестиком, треугольником)
    double det() {
        if (N == M) {
            switch (N) {
            case 1:
                return matrix[0][0];
            case 2:
                return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
            case 3:
                return (((matrix[0][0] * matrix[N - 2][N - 2] * matrix[N - 1][N - 1]) + (matrix[0][N - 2] * matrix[N - 2][N - 1] * matrix[N - 1][0]) + \
                    (matrix[N - 2][0] * matrix[N - 1][N - 2] * matrix[0][N - 1])) - \
                    ((matrix[0][N - 1] * matrix[N - 2][N - 2] * matrix[N - 1][0]) + (matrix[0][N - 2] * matrix[N - 2][0] * matrix[N - 1][N - 1]) + \
                        (matrix[N - 1][N - 2] * matrix[N - 2][N - 1] * matrix[0][0])));
            }
        }
        else {
            abort();
        }
    }

    // ввод/вывод в поток
    template<typename T, int N, int M>
    friend istream& operator >>(istream& in, Matrix<T, N, M>& matrix);
    template<typename T, int N, int M>
    friend ostream& operator <<(ostream& out, Matrix<T, N, M>& matrix);
};

// оператор вывода в поток
template<typename T, int N, int M>
ostream& operator <<(ostream& out, Matrix<T, N, M>& matrix)
{
    out << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            out << matrix.matrix[i][j] << "\t";
        }
        out << endl;
    }
    return out;
}

// оператор ввода в поток
template<typename T, int N, int M>
istream& operator >>(istream& in, Matrix<T, N, M>& matrix)
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << "[" << i << "][" << j << "]: ";
            in >> matrix.matrix[i][j];
        }
    }
    return in;
}


using Matrix22 = Matrix<int, 2, 2>;
using Matrix11 = Matrix<int, 2, 1>;

int main()
{
    Matrix22 matrix;
    cout << endl << "Matrix 1:" << endl;
    cin >> matrix;
    cout << matrix;
    Matrix11 matrix2;
    cout << endl << "Matrix 2:" << endl;
    cin >> matrix2;
    cout << matrix2;

    // конструктор копирования
    Matrix22 matrix3(matrix);
    cout << endl << "Matrix 3:" << matrix3;

    cout << endl << "Matrix 3:" << endl;
    cin >> matrix3;

    // опрератор присваивания копированием
    matrix = matrix3;
    cout << endl << "Matrix 1 = Matrix 3:" << endl << matrix;

    // оператор +=
    matrix += matrix3;
    cout << endl << "Matrix 1 += Matrix 3" << endl << matrix;

    // оператор +
    Matrix22 matrix4 = matrix + matrix3;
    cout << endl << "Matrix 4 = Matrix 1 + Matrix 3" << endl << matrix4 << endl;

    // оператор *
    auto matrix5 = matrix4 * matrix2;
    cout << "Matrix 4 * Matrix 3 " << endl << matrix5 << endl;

    // оператор ++ (префиксный и постфиксный)
    ++matrix5;
    matrix5++;
    cout << "++Matrix 5 and Matrix 5++" << endl << matrix5 << endl;

    // определитель
    cout << "Determinant of Matrix 4: " << matrix4.det() << endl;

    // возвращение и изменение элемента по индексу через []
    cout << "Matrix5[0][0]: " << matrix5[0][0] << endl;
    cout << "Matrix5[0][0] = 1000" << endl;
    matrix5[0][0] = 1000;
    cout << matrix5 << endl << endl;

    // возвращение и изменения элемента по индексу через метод
    cout << "Matrix5.el(0, 0): " << matrix5.el(0, 0) << endl;
    cout << "Matrix5.el(0, 0) = 5555" << endl;
    matrix5.el(0, 0) = 5555;
    cout << matrix5 << endl;
}
