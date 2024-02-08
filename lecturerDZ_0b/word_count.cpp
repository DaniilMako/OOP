#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {  // компаратор дл€ функции сортировки
    return a.second > b.second;
}

vector<pair<string, int>> sort(map<string, int>& M) {  // сортировка
    vector<pair<string, int> > A;

    for (auto& it : M)
        A.push_back(it);
    sort(A.begin(), A.end(), cmp);

    return A;
}

int main() {
//int main(int argc, char** argv) {
    system("chcp 1151");  // дл€ нормальной работы с криллицей
    std::ifstream infile("input.txt");  // открытие вводного файла
    //std::ifstream infile(argv[1]);  // открытие вводного файла
    if (!infile) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    std::map<std::string, int> word_count;  // <слово, частота>
    std::string line;  // строка
    double count = 0;
    while (std::getline(infile, line)) {
        for (char& ch : line) {
            if (ch == '<' or ch == '>' or ch == '?' or ch == '!' or ch == '.' or ch == ',' or ch == ':' or ch == ';' or ch == '/' or ch == '\\' or ch == '=' or ch == '-' or ch == '+' or ch == 'Ц' or ch == '#' or ch == '"' or ch == '\'' or ch == '*') {
                ch = ' ';
            }
        }

        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            ++word_count[word];
            count += 1;
        }

        cout << line << endl;

    }

    infile.close();  // закрытие вводного файла
    vector<pair<string, int>> M = sort(word_count);  // сортировка по убыванию частоты

    std::ofstream outfile("output.csv");  // выходной файл
    outfile << "—лово;„астота;„астота(%)\n";  // столбцы —лово;„астота;„астота(%)  //если написать по-русски, то ломаетс€ кодировка (по крайней мере в VS)

    for (auto& entry : M) {  // вывод
        double percentage = double(entry.second * 100) / count;  // частота(%)

        char separator = ';';  // разделитель столбцов

        outfile << entry.first << separator  //вывод слова
            << entry.second << separator  // вывод частоты
            << percentage << '\n';  // вывод частоты(%)
    }
    std::cout << "Done!";
    outfile.close();
    return 0;
}
