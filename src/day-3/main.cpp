#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>

typedef enum {
    KW_NONE = 0,
    KW_MUL,
    KW_DO,
    KW_DONT
} KW;

std::string read_file(const char *file_name) {

    std::ifstream inFile;
    inFile.open(file_name); //open the input file

    if (!inFile.is_open()) {
        std::cerr << "Could not open file " << file_name << std::endl;
        return "";
    }

    std::stringstream strStream;
    strStream << inFile.rdbuf(); //read the file
    std::string str = strStream.str(); //str holds the content of the file

    return str;
}

KW find_next_kw(const std::string* str, int* pointer) {
    while (true) {
        if (*pointer+13 >= str->size()) {
            return KW_NONE;
        }
        if (str->at(*pointer) == 'm' && str->at(*pointer+1) == 'u' && str->at(*pointer+2) == 'l') {
            *pointer += 3;
            return KW_MUL;
        }
        if (str->at(*pointer) == 'd' && str->at(*pointer+1) == 'o' && str->at(*pointer+2) == 'n' && str->at(*pointer+3) == '\'' && str->at(*pointer+4) == 't') {
            *pointer += 5;
            return KW_DONT;
        }
        if (str->at(*pointer) == 'd' && str->at(*pointer+1) == 'o') {
            *pointer += 2;
            return KW_DO;
        }

        (*pointer)++;
    }
}

int parse_number(const std::string* str, int* pointer, bool* two_digit) {
    int number = 0;
    if (str->at(*pointer) >= '0' && str->at(*pointer) <= '9') {
        number = atoi(str->substr(*pointer, 1).c_str());
    } else {
        return -1;
    }
    (*pointer)++;
    const int delta = parse_number(str, pointer, two_digit);
    if (delta != -1) {
        number *= 10;
        if (*two_digit) {
            number *= 10;
        }
        number += delta;
        if (number < 1000) {
            *two_digit = true;
            return number;
        }
        return -1;
    }
    *two_digit = false;
    return number;
}

int parse_string(const std::string *str) {
    int result = 0;
    int pointer = 0;
    bool enabled = true;

    while (true) {
        const KW kw = find_next_kw(str, &pointer);
        if (kw == KW_NONE) {
            break;
        } else if (kw == KW_DO) {
            if (str->at(pointer) != '(') {
                pointer++;
                continue;
            }
            pointer++;

            if (str->at(pointer) != ')') {
                pointer++;
                continue;
            }
            pointer++;

            enabled = true;
        } else if (kw == KW_DONT) {
            if (str->at(pointer) != '(') {
                pointer++;
                continue;
            }
            pointer++;

            if (str->at(pointer) != ')') {
                pointer++;
                continue;
            }
            pointer++;

            enabled = false;
        } else if (kw == KW_MUL) {
            if (str->at(pointer) != '(') {
                pointer++;
                continue;
            }
            pointer++;

            bool temp = false;
            const int num1 = parse_number(str, &pointer, &temp);
            if (num1 == -1) {
                continue;
            }

            if (str->at(pointer) != ',') {
                pointer++;
                continue;
            }
            pointer++;

            temp = false;
            const int num2 = parse_number(str, &pointer, &temp);
            if (num2 == -1) {
                continue;
            }

            if (str->at(pointer) != ')') {
                pointer++;
                continue;
            }
            pointer++;
            if (enabled) {
                result += num1 * num2;
            }
        }

    }

    return result;
}


int main() {
    const std::string file_contents = read_file("./data/day-3/instructions.txt");

    const int result = parse_string(&file_contents);

    std::cout << result << std::endl;

}