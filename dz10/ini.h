#pragma once

#include <istream>
#include <string>
#include <unordered_map>
#include <set>


namespace Ini {
    using namespace std;
    using Section = set<pair<string, string>>;

    class Document {
    public:
        Section &AddSection(string name);

        const Section &GetSection(const string &name) const;

        size_t SectionCount() const;

    private:
        unordered_map<string, Section> sections;
    };

    Document Load(istream &input);
}
