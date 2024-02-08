//#include <iostream>
//#include <fstream>
//#include <string>
//#include <sstream>
//#include <unordered_map>
//#include <vector>
//#include <algorithm>
//#include <list>
//
//bool cmp(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
//    return a.second > b.second;
//}
//
//std::vector<std::pair<std::string, int>> sort(const std::unordered_map<std::string, int>& word_count) {
//    std::vector<std::pair<std::string, int>> sorted_words(word_count.begin(), word_count.end());
//    std::sort(sorted_words.begin(), sorted_words.end(), cmp);
//    return sorted_words;
//}
//
//std::unordered_map<std::string, int> countWords(const std::list<std::string>& lines) {
//    std::unordered_map<std::string, int> word_count;
//    for (const std::string& line : lines) {
//        std::stringstream ss(line);
//        std::string word;
//        while (ss >> word) {
//            ++word_count[word];
//        }
//    }
//    return word_count;
//}
//
//std::vector<std::string> getNumbersAndWords(const std::string& str) {
//    std::vector<std::string> result;
//    std::string current;
//
//    for (char c : str) {
//        if (std::isalnum(c)) {
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
//int main(int argc, char* argv[]) {
//    //    if (argc != 3) {
//    //        std::cerr << "Invalid number of arguments. Usage: word_count.exe input.txt output.csv\n";
//    //        return 1;
//    //    }
//
//    std::ifstream infile("input.txt");
//    if (!infile) {
//        std::cerr << "Error opening input file.\n";
//        return 1;
//    }
//
//    std::list<std::string> lines;
//    std::string line;
//    while (std::getline(infile, line))
//        lines.push_back(line);
//    infile.close();
//
//    std::unordered_map<std::string, int> word_count = countWords(lines);
//    std::vector<std::pair<std::string, int>> sorted_words = sort(word_count);
//
//    std::ofstream outfile("output.csv");
//    if (!outfile) {
//        std::cerr << "Error opening output file.\n";
//        return 1;
//    }
//
//    outfile << "Word;Frequency;Frequency(%)\n";  //если написать по-русски, то ломается кодировка (по крайней мере в VS)
//    int total_words = lines.size();
//
//    for (const auto& entry : sorted_words) {
//        double percentage = static_cast<double>(entry.second) / total_words * 100;
//        outfile << entry.first << ";" << entry.second << ";" << percentage << "\n";
//    }
//
//    outfile.close();
//
//    std::cout << "CSV file created successfully!\n";
//
//    return 0;
//}