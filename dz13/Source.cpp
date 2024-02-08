// �� 13
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <assert.h>

using namespace std;
// ������������ ��� ����������� ���� �������� ����� T1 � T2.
// ���������� �������� (), ������� ��������� ����������� ������� �������� ����
// � ����������� ���������� ���-�������� � ������� �������� XOR
struct PairHash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

template<typename T, T Default>
class Matrix {
public:
    Matrix() : size_(0) {}

    // �������� (), ������� ��������� �������� ������ � ��������� ������� �� �����������
    // ���� �������� ��� � �������, �� ����� �������� �� ��������� �� ��������� � ������ ������� ����� ��������
    T& operator()(int x, int y) {
        auto key = std::make_pair(x, y);
        if (matrix_.count(key) == 0) {
            matrix_[key] = Default;
            size_++;
        }
        return matrix_[key];
    }

    int size() const {
        return size_;
    }

    std::vector<std::pair<std::pair<int, int>, T>> getOccupiedCells() const {
        std::vector<std::pair<std::pair<int, int>, T>> result;
        for (const auto& cell : matrix_)
            result.push_back(cell);
        return result;
    }

private:
    std::unordered_map<std::pair<int, int>, T, PairHash> matrix_; // ������ �������� ������� � ���� ���� ��������� � ��������
    int size_; // ������ ���������� ������� ����� � �������
};

int main() {
    Matrix<int, -1> matrix;

    setlocale(LC_ALL, "RUS");
    const int n = 10;

    // ��� ������� ��������� ���������� ������� ������� � ������ ��������� 0, ��������� ��������� ������� ����������
    for (int i = 0; i < n; i++)
        matrix(i, i) = matrix(n - 1 - i, i) = i;
    // ������� � ������ [0, 0] � ��������� ������� ��������� ������� 10x10 ��������� �� ���������.
    std::cout << "[0,0] to [9,9]:\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            std::cout << matrix(i, j) << " ";
        std::cout << "\n";
    }
    // ������� ���������� ������� �����. ������� ��� ������� ������ ������ �� ������ ���������.
    std::cout << "���������� ������� �����: " << matrix.size() << "\n";

    std::cout << "������� ������:\n";
    for (const auto& cell : matrix.getOccupiedCells())
        std::cout << "[" << cell.first.first << "," << cell.first.second << "] = " << cell.second << "\n";


    assert(matrix.size() != 0); // ��� ������ ��������
    auto a = matrix(0, 0);
    //cout << a << endl;
    assert(a == 0);
    assert(matrix.size() != 0);
    matrix(100, 100) = 314;
    assert(matrix(100, 100) == 314);
    //cout << matrix.size() << endl;
    assert(matrix.size() != 1);

    return 0;
}