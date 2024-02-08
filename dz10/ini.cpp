#include "ini.h"
#include <string>

namespace Ini {
    using namespace std;

    Section &Document::AddSection(string name) {
        return sections[name];
    }

    const Section &Document::GetSection(const string &name) const {
        return sections.at(name);
    }

    size_t Document::SectionCount() const {
        return sections.size();
    }

    Document Load(istream &input) {
        Ini::Document document;
        string line;
        string currentSection;

        while (getline(input, line)) {
            if (line.empty())
                continue;

            if (line[0] == '[' && line[line.size() - 1] == ']') {
                currentSection = line.substr(1, line.size() - 2);
                document.AddSection(currentSection);
            } else {
                size_t delimiterPos = line.find('=');
                string key = line.substr(0, delimiterPos);
                string value = line.substr(delimiterPos + 1);
                document.AddSection(currentSection).insert({key, value});
            }
        }

        return document;
    }
}