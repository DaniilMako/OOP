#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, int>& a, pair<string, int>& b) {  // ���������� ��� ������� ����������
    return a.second > b.second;
}

vector<pair<string, int>> sort(map<string, int>& M) {  // ����������
    vector<pair<string, int> > A;

    for (auto& it : M)
        A.push_back(it);
    sort(A.begin(), A.end(), cmp);

    return A;
}

int main() {
//int main(int argc, char** argv) {
    system("chcp 1151");  // ��� ���������� ������ � ���������
    std::ifstream infile("input.txt");  // �������� �������� �����
    //std::ifstream infile(argv[1]);  // �������� �������� �����
    if (!infile) {
        std::cerr << "Error opening input file.\n";
        return 1;
    }

    std::map<std::string, int> word_count;  // <�����, �������>
    std::string line;  // ������
    double count = 0;
    while (std::getline(infile, line)) {
        for (char& ch : line) {
            if (ch == '<' or ch == '>' or ch == '?' or ch == '!' or ch == '.' or ch == ',' or ch == ':' or ch == ';' or ch == '/' or ch == '\\' or ch == '=' or ch == '-' or ch == '+' or ch == '�' or ch == '#' or ch == '"' or ch == '\'' or ch == '*') {
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

    infile.close();  // �������� �������� �����
    vector<pair<string, int>> M = sort(word_count);  // ���������� �� �������� �������

    std::ofstream outfile("output.csv");  // �������� ����
    outfile << "�����;�������;�������(%)\n";  // ������� �����;�������;�������(%)  //���� �������� ��-������, �� �������� ��������� (�� ������� ���� � VS)

    for (auto& entry : M) {  // �����
        double percentage = double(entry.second * 100) / count;  // �������(%)

        char separator = ';';  // ����������� ��������

        outfile << entry.first << separator  //����� �����
            << entry.second << separator  // ����� �������
            << percentage << '\n';  // ����� �������(%)
    }
    std::cout << "Done!";
    outfile.close();
    return 0;
}
