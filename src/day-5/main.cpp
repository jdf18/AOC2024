#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <regex>

typedef struct {
    int lower;
    int upper;
} Rule;

std::vector<std::string> read_lines(const std::string& file_name) {
    std::vector<std::string> lines;
    std::ifstream file(file_name);

    if (!file.is_open()) {
        std::cerr << "Could not open file " << file_name << std::endl;
        return lines;
    }

    std::string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

bool test_ordering(const std::vector<int>& ordering, const std::vector<Rule>& rules) {
    for (int index_1 = 0; index_1 < ordering.size(); index_1++) {
        const int test_case_1 = ordering[index_1];
        for (int index_2=0; index_2 < ordering.size(); index_2++) {
            if (index_1 == index_2) continue;
            const int test_case_2 = ordering[index_2];

            for (const Rule& rule : rules) {
                if (rule.lower == test_case_1 && rule.upper == test_case_2) {
                    if (index_1 > index_2) return false;
                } else if (rule.lower == test_case_2 && rule.upper == test_case_1) {
                    if (index_2 > index_1) return false;
                }
            }
        }
    }
    return true;
}

void fix_ordering(std::vector<int>& ordering, const std::vector<Rule>& rules) {
    std::sort(ordering.begin(), ordering.end());

    std::vector<std::vector<int>> permutations;

    do {
        if (test_ordering(ordering, rules)) {
            return;
        }
    } while (std::next_permutation(ordering.begin(), ordering.end()));

    return;
}

int main() {
    const std::vector<std::string> contents = read_lines("./data/day-5/updates.txt");

    std::vector<Rule> rules = {};

    const std::regex re_rule("([0-9]{2})\\|([0-9]{2})");
    const std::regex re_update("\\d{2}");
    std::smatch match;

    int count_1 = 0;
    int count_2 = 0;
    bool parsing_rules = true;
    for (const std::string& line : contents) {
        if (parsing_rules) {
            if (line.length() <= 1) {
                parsing_rules = false;
                continue;
            }
            if (std::regex_match(line, match, re_rule))
            {
                Rule current_rule;
                current_rule.lower = std::stoi(match[1]);
                current_rule.upper = std::stoi(match[2]);
                rules.push_back(current_rule);
            }
        } else {
            std::sregex_iterator begin(line.begin(), line.end(), re_update), end;
            std::vector<int> update;

            for (auto it = begin; it != end; ++it) {
                update.push_back(std::stoi(it->str()));
            }

            if (test_ordering(update, rules)) {
                count_1 += update[update.size()/2];
            } else {
                fix_ordering(update, rules);
                if (test_ordering(update, rules)) {
                    std::cout << "ordered" << std::endl;
                } else {
                    std::cout << "not ordered" << std::endl;
                }
                count_2 += update[update.size()/2];
            }
        }
    }

    std::cout << count_1 << std::endl;
    std::cout << count_2 << std::endl;

    return 0;
}