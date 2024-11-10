#include <iostream>
#include <vector>
using namespace std;

class Matrix {
private:
    int numRow, numColumn;
    vector<vector<int>> matrix;

public:
    Matrix(int row = 0, int column = 0) : numRow(row), numColumn(column) {
        matrix.resize(row, vector<int>(column, 0));
    }

    void input() {
        cout << "Nhập số hàng: "; cin >> numRow;
        cout << "Nhập số cột: "; cin >> numColumn;

        matrix.resize(numRow, vector<int>(numColumn));

        cout << "Nhập các phần tử của ma trận:\n";
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numColumn; j++) {
                cout << "Phần tử [" << i + 1 << "][" << j + 1 << "]: ";
                cin >> matrix[i][j];
            }
        }
    }

    void output() const {
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numColumn; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix operator + (const Matrix& other) const {
        if (numRow != other.numRow || numColumn != other.numColumn) {
            cout << "Kích thước ma trận không phù hợp để cộng!\n";
            return Matrix();
        }

        Matrix result(numRow, numColumn);
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numColumn; j++) {
                result.matrix[i][j] = matrix[i][j] + other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator - (const Matrix& other) const {
        if (numRow != other.numRow || numColumn != other.numColumn) {
            cout << "Kích thước ma trận không phù hợp để trừ!\n";
            return Matrix();
        }

        Matrix result(numRow, numColumn);
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < numColumn; j++) {
                result.matrix[i][j] = matrix[i][j] - other.matrix[i][j];
            }
        }
        return result;
    }

    Matrix operator * (const Matrix& other) const {
        if (numColumn != other.numRow) {
            cout << "Kích thước ma trận không phù hợp để nhân!\n";
            return Matrix();
        }

        Matrix result(numRow, other.numColumn);
        for (int i = 0; i < numRow; i++) {
            for (int j = 0; j < other.numColumn; j++) {
                result.matrix[i][j] = 0;
                for (int k = 0; k < numColumn; k++) {
                    result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
                }
            }
        }
        return result;
    }
};

int main() {
    Matrix mat1, mat2;

    cout << "Nhập ma trận thứ nhất:\n";
    mat1.input();
    cout << "Nhập ma trận thứ hai:\n";
    mat2.input();

    cout << "\nTổng hai ma trận:\n";
    Matrix tong = mat1 + mat2;
    tong.output();

    cout << "\nHiệu hai ma trận:\n";
    Matrix hieu = mat1 - mat2;
    hieu.output();

    cout << "\nTích hai ma trận:\n";
    Matrix tich = mat1 * mat2;
    tich.output();

    return 0;
}