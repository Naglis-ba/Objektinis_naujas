#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

bool isWordChar(unsigned char c) {
    return std::isalnum(c) || c == '\'';
}

void countFrequencies(const std::string& str, std::unordered_map<std::string, int>& freq) {
    std::ifstream in (str);
    std::string line;
    while (getline(in, line)) {
        string word;
        for (char c : line) {
            if(isWordChar(c)) 
            {
                word += std::tolower(c);
            } 
            else if (!word.empty()) 
            {
                freq[word]++;
                word.clear();
            }
        }
        if (!word.empty()) {
            freq[word]++;
        }
    }
}


int main() {
    std::unordered_map<std::string, int> freq;
    
    countFrequencies("input.txt", freq);

    std::vector<std::pair<std::string, int>> items;
    items.reserve(freq.size());
    for (auto &kv : freq) {
        if (kv.second > 1) items.push_back(kv);
    }

    std::sort(items.begin(), items.end(),
          [](auto &a, auto &b){
              if (a.second != b.second) return a.second > b.second;
              return a.first < b.first;
          });

    std::ofstream out("rezultatai.txt");
    for (auto &p : items) {
    out << p.first << " " << p.second << "\n";
    }

}