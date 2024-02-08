// ДЗ 13
#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
#include <assert.h>

using namespace std;
// используется для хеширования пары значений типов T1 и T2.
// определяет оператор (), который выполняет хеширование каждого элемента пары
// и комбинирует полученные хеш-значения с помощью операции XOR
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

    // оператор (), который позволяет получить доступ к элементам матрицы по координатам
    // если элемента нет в матрице, он будет добавлен со значением по умолчанию и размер матрицы будет увеличен
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
    std::unordered_map<std::pair<int, int>, T, PairHash> matrix_; // хранит элементы матрицы в виде пары координат и значения
    int size_; // хранит количество занятых ячеек в матрице
};

int main() {
    Matrix<int, -1> matrix;

    setlocale(LC_ALL, "RUS");
    const int n = 10;

    // При запуске программы необходимо создать матрицу с пустым значением 0, заполнить диагонали матрицы выражением
    for (int i = 0; i < n; i++)
        matrix(i, i) = matrix(n - 1 - i, i) = i;
    // Начиная с ячейки [0, 0] в шахматном порядке заполнить матрицу 10x10 значением по умолчанию.
    std::cout << "[0,0] to [9,9]:\n";
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++)
            std::cout << matrix(i, j) << " ";
        std::cout << "\n";
    }
    // Вывести количество занятых ячеек. Вывести все занятые ячейки вместе со своими позициями.
    std::cout << "Количество занятых ячеек: " << matrix.size() << "\n";

    std::cout << "Занятые ячейки:\n";
    for (const auto& cell : matrix.getOccupiedCells())
        std::cout << "[" << cell.first.first << "," << cell.first.second << "] = " << cell.second << "\n";


    assert(matrix.size() != 0); // все ячейки свободны
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