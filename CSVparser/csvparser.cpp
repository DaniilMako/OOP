#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <tuple>

template <typename Ch, typename Tr, size_t I, typename... Args>
class TuplePrinter {  // ���������� �������� ���������� �������
public:
    static void print(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t) {  // ���������� �������� ���������� �������
        TuplePrinter<Ch, Tr, I - 1, Args...>::print(os, t);
        if (I < sizeof...(Args))
            os << " ";
        os << std::get<I>(t);
    }
};

template <typename Ch, typename Tr, typename... Args>
class TuplePrinter<Ch, Tr, -1, Args...> {  // ���������� �������� ���������� ������� #2
public:
    static void print(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t) {}
};

template <typename Ch, typename Tr, typename... Args>
auto operator<<(std::basic_ostream<Ch, Tr>& os, const std::tuple<Args...>& t) {  // ��� ������ ������� � �������
    TuplePrinter<Ch, Tr, sizeof...(Args) - 1, Args...>::print(os, t);
}



template <typename Type>
Type setArgument(std::string inputValue) {  // ����������� ��������� �������� � �������� ��� ������
    Type arg;
    std::stringstream buffer;
    // ��� �������������� ������ � Type
    buffer << inputValue;
    buffer >> arg;

    return arg;
}

template <typename... Args>
class CSVParser {  // ����� ������� ��� ������� csv-������
public:
    std::ifstream& file;
    int skipLinesCount;  // ������� ����� ����������
    char delimiter;  // 1,2,3 \, 4,5,6, 7\,8
    char quoteChar;  // �������������
    bool end_file = false;
    std::tuple<Args...> buffer;

    ~CSVParser() = default;
    CSVParser(std::ifstream& file, int skipLinesCount = 0, char delimiter = ',', char quoteChar = '"') :file(file) {
        this->skipLinesCount = skipLinesCount;
        this->delimiter = delimiter;
        this->quoteChar = quoteChar;

        for (int i = 0; i < skipLinesCount; i++) {  // ���������� ��������� ���������� �����
            std::string line;
        std:getline(file, line);
        }
        this->buffer = vector2tuple();
    }

    class CSVInputIterator {  //LegacyInputIterator
    public:
        CSVInputIterator(CSVParser<Args...>* _object = nullptr) : object(_object) {};

        bool operator!=(CSVInputIterator& b) { return this->object != b.object; }

        std::tuple<Args...> operator*() { return object->buffer; }  // ��������� ��� buffer
        CSVInputIterator& operator++() {  // ��� buffer++
            try {
                object->buffer = object->vector2tuple();
            }
            catch (std::runtime_error& e) {
                object = nullptr;
            }

            return *this;
        }

        CSVParser<Args...>* object;
    };

    CSVInputIterator begin() { return CSVInputIterator(this); }  // ��������� �� ������
    CSVInputIterator end() { return CSVInputIterator(); }  // ��������� �� �����

    std::tuple<Args...> vector2tuple() {  // ����������� ������ ����� � ������ ��������
        std::vector<std::string> output = row2vector();

        auto func = [&output]() -> std::string {  // ������ ������ �� �������
            std::string firstElement = output.front();
            output.erase(output.begin());
            return firstElement;
            };
        if (end_file)
            exit(0);
        if (output.size() != sizeof...(Args))
            throw;
        return std::tuple<Args...>(setArgument<Args>(func())...);  // ��������� ������ � tuple
    }

    std::vector<std::string> row2vector() {  // �������� ������� �� ������
        std::vector<std::string> data;
        std::string line;
        if (std::getline(file, line)) {
            std::stringstream linestream(line);  // ��������� ������
            std::string cell;
            std::string supercell = "";
            int column = 0;
            while (std::getline(linestream, cell, delimiter)) {  // ��������� ������
                if (!cell.empty() && cell.back() != quoteChar) {  // ��� �������
                    supercell = supercell + cell;
                    data.push_back(supercell);
                    supercell = "";
                }
                else
                    if (!cell.empty() && cell.back() == quoteChar) {  // ���� �������
                        cell.pop_back();
                        supercell = cell + delimiter;
                    }
            }
            return data;
        }

        if (file.eof())
            end_file = true;
    }
};



int main() {
    std::ifstream file("tabl.csv");

    CSVParser<int, int, int, int, std::string> parser(file, 0, ',', '/');

    for (auto row : parser) {
        std::cout << row;
        std::cout << std::endl;
    }


    return 0;
}
