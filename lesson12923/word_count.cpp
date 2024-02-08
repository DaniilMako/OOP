#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
//#include <list>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>& a,
    pair<string, int>& b) {
    return a.second > b.second;
}

vector<pair<string, int>> sort(map<string, int>& M) {  // сортировка
    vector<pair<string, int> > A;

    for (auto& it : M)
        A.push_back(it);
    sort(A.begin(), A.end(), cmp);

    return A;
}

std::vector<std::string> getNumbersAndWords(const std::string& str) {
    std::vector<std::string> result;
    std::string current;

    for (char c : str) {
        if (isdigit(c)) {
            current += c;
        }
        else if (isalpha(c)) {
            current += c;
        }
        else if (!current.empty()) {
            result.push_back(current);
            current.clear();
        }
    }

    if (!current.empty()) {
        result.push_back(current);
    }

    return result;
}

int main() {
    std::ifstream infile("input.txt");  // открытие вводного файла
    if (!infile) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    std::map<std::string, int> word_count;  // <слово, частота>
    std::string line;  // строка
    double count = 0;
    while (std::getline(infile, line)) {
        for (char& ch : line) {
            if (ch == '<' or ch == '>' or ch == '?' or ch == '!' or ch == '.' or ch == ',' or ch == ':' or ch == ';' or ch == '/' or ch == '\\' or ch == '=' or ch == '-' or ch == '+' or ch == '–' or ch == '#' or ch == '"' or ch == '\'' or ch == '*') {
                ch = ' ';
            }
        }
        /*std::vector<std::string> tokens = getNumbersAndWords(line);*/

        std::stringstream ss(line);
        std::string word;

        while (ss >> word) {
            ++word_count[word];
            count += 1;
        }

        cout << line << endl;

    }
    //return 0;

    infile.close();  // закрытие вводного файла
    vector<pair<string, int>> M = sort(word_count);  // сортировка по убыванию частоты

    std::ofstream outfile("output.csv");  // выходной файл
    outfile << "Word;Frequency;Frequency(%)\n";  // столбцы Слово;Частота;Частота(%)  //если написать по-русски, то ломается кодировка (по крайней мере в VS)

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




//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <map>
////#include <list>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//bool cmp(pair<string, int>& a,
//    pair<string, int>& b) {
//    return a.second > b.second;
//}
//
//vector<pair<string, int>> sort(map<string, int>& M) {  // сортировка
//    vector<pair<string, int> > A;
//
//    for (auto& it : M)
//        A.push_back(it);
//    sort(A.begin(), A.end(), cmp);
//
//    return A;
//}
//
//std::vector<std::string> getNumbersAndWords(const std::string& str) {
//    std::vector<std::string> result;
//    std::string current;
//
//    for (char c : str) {
//        if (isdigit(c)) {
//            current += c;
//        }
//        else if (isalpha(c)) {
//            current += c;
//        }
//        else if (!current.empty()) {
//            result.push_back(current);
//            current.clear();
//        }
//    }
//
//    if (!current.empty()) {
//        result.push_back(current);
//    }
//
//    return result;
//}
//
//int main() {
//    std::ifstream infile("input.txt");  // откртытие вводного файла
//    if (!infile) {
//        std::cerr << "Error opening input file.\n";
//        return 1;
//    }
//
//    std::map<std::string, int> word_count;  // <слово, частота>
//    std::string line;  // строка
//
//    while (std::getline(infile, line)) {
//        std::vector<std::string> str = {};
//        std::string tmp = "";
//        for (char& ch : line) {
//            if (isalnum(ch))
//                tmp += ch;
//            if (!isalnum(ch)) {
//                str.push_back = tmp;
//                tmp = "";
//            }
//        }
//        /*std::vector<std::string> tokens = getNumbersAndWords(line);*/
//
//        std::stringstream ss(line);
//        std::string word;
//
//        while (ss >> word)
//            ++word_count[word];
//
//        //cout << line << endl;
//
//    }
//    //return 0;
//
//    infile.close();  // закрытие вводного файла
//    vector<pair<string, int>> M = sort(word_count);  // сортировка по убыванию частоты
//
//    std::ofstream outfile("output.csv");  // выходной файл
//    outfile << "Слово;Частота;Частота(%)\n";  // столбцы Слово;Частота;Частота(%)  //если написать по-русски, то ломается кодировка (по крайней мере в VS)
//
//    for (auto& entry : M) {  // вывод
//        double percentage = static_cast<double>(entry.second) /
//            static_cast<double>(M.
//                size());
//        percentage *= 100;  // частота(%)
//
//        char separator = ';';
//
//        outfile << entry.first << separator
//            << entry.second << separator
//            << std::fixed
//            << percentage << '\n';
//    }
//    std::cout << "Done!";
//    outfile.close();
//    return 0;
//}