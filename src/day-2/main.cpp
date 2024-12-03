#include <fstream>
#include <iostream>
#include <ostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>

void print_vec(std::vector<int> vec) {
    std::cout << '[';
    bool first = true;
    for (const int& num : vec) {
        if (!first) std::cout << ", ";
        std::cout << num;
        first = false;
    }
    std::cout << ']' << std::endl;
}

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

std::vector<int> split_integers(const std::string* line, const char delimiter) {
    std::vector<int> result;
    std::stringstream ss(*line);
    std::string token;

    while (std::getline(ss, token, delimiter)) {
        result.push_back(std::stoi(token));
    }

    return result;
}

std::vector<std::vector<int>> parse_lines(const std::vector<std::string>& lines) {
    std::vector<std::vector<int>> result;
    for (const std::string &line : lines) {
        result.push_back(split_integers(&line, ' '));
    }
    return result;
}

bool test_levels(const std::vector<int>& levels) {
    const bool increasing = (levels[0] < levels[1]);
    for (int j = 1; j < levels.size(); j++) {
        const int delta = levels[j] - levels[j-1];
        if ((increasing && delta < 0) || (!increasing && delta > 0)) {
            return false;
        }
        if (1 > abs(delta) || abs(delta) > 3) {
            return false;
        }
    }
    return true;
}

int main() {
    const std::vector<std::string> lines = read_lines("./data/day-2/reports.txt");
    const std::vector<std::vector<int>> results = parse_lines(lines);

    int count = 0;
    for (int i = 0; i < results.size(); i++) {
        std::cout << std::endl;
        print_vec(results[i]);
        bool result = test_levels(results[i]);
        for (int j = 0; j < results[i].size(); j++) {
            std::vector<int> test_case;
            for (int k = 0; k < results[i].size(); k++) {
                if (k == j) {continue;}
                test_case.push_back(results[i][k]);
            }
            result = result || test_levels(test_case);
            std::cout << test_levels(test_case);
            print_vec(test_case);
        }
        if (result == true) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}