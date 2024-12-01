#include "main.h"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> read_lines(const string& file_name) {
    vector<string> lines;
    ifstream file(file_name);

    if (!file.is_open()) {
        cerr << "Could not open file " << file_name << endl;
        return lines;
    }

    string line;
    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();
    return lines;
}

int count(const vector<int>& list, const int query) {
    int count = 0;
    for (const int i : list) {
        if (i == query) {
            count++;
        }
    }
    return count;
}

bool compare(int a, int b) {
    return a >= b;
}

int main() {
    vector<string> lines = read_lines("./data/day-1/lists.txt");

    vector<int> list1, list2;

    for (const auto & line : lines) {
        int num1 = atoi(line.substr(0, 5).c_str());
        list1.push_back(num1);
        int num2 = atoi(line.substr(8, 5).c_str());
        list2.push_back(num2);
    }

    sort(list1.begin(), list1.end(), compare);
    sort(list2.begin(), list2.end(), compare);

    int sum = 0;
    for (int i = 0; i < list1.size(); i++) {
        sum += abs(list1[i] - list2[i]);
    }

    cout << sum << endl;

    // * Part 2

    int similarity_score = 0;
    for (const int i : list1) {
        similarity_score += i * count(list2, i);
    }

    cout << similarity_score << endl;

    return 0;
}