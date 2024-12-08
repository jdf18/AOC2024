#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

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

char get_char(const std::vector<std::string> &file, const int x, const int y) {
    if (y >= file.size() || y < 0) {
        return -1;
    }
    if (x < 0 || x >= file[0].length()) {
        return -1;
    }
    return file[y][x];
}

int main() {
    std::vector<std::string> contents = read_lines("./data/day-4/wordsearch.txt");

    const unsigned long height = contents.size();
    const unsigned long width = contents[0].length();

    int count = 0;
    // Check for words going right
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x, y) != 'X') {
                continue;
            }
            if (get_char(contents, x+1, y) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y) != 'A') {
                continue;
            }
            if (get_char(contents, x+3, y) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for words going left
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x, y) != 'X') {
                continue;
            }
            if (get_char(contents, x-1, y) != 'M') {
                continue;
            }
            if (get_char(contents, x-2, y) != 'A') {
                continue;
            }
            if (get_char(contents, x-3, y) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for words going up
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x, y) != 'X') {
                continue;
            }
            if (get_char(contents, x, y+1) != 'M') {
                continue;
            }
            if (get_char(contents, x, y+2) != 'A') {
                continue;
            }
            if (get_char(contents, x, y+3) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for words going down
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x, y) != 'X') {
                continue;
            }
            if (get_char(contents, x, y-1) != 'M') {
                continue;
            }
            if (get_char(contents, x, y-2) != 'A') {
                continue;
            }
            if (get_char(contents, x, y-3) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for words going right and up
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x, y) != 'X') {
                continue;
            }
            if (get_char(contents, x+1, y+1) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y+2) != 'A') {
                continue;
            }
            if (get_char(contents, x+3, y+3) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for words going right and down
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x, y) != 'X') {
                continue;
            }
            if (get_char(contents, x+1, y-1) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y-2) != 'A') {
                continue;
            }
            if (get_char(contents, x+3, y-3) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for words going left and up
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x, y) != 'X') {
                continue;
            }
            if (get_char(contents, x-1, y+1) != 'M') {
                continue;
            }
            if (get_char(contents, x-2, y+2) != 'A') {
                continue;
            }
            if (get_char(contents, x-3, y+3) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for words going left and down
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x, y) != 'X') {
                continue;
            }
            if (get_char(contents, x-1, y-1) != 'M') {
                continue;
            }
            if (get_char(contents, x-2, y-2) != 'A') {
                continue;
            }
            if (get_char(contents, x-3, y-3) != 'S') {
                continue;
            }
            count++;
        }
    }

    std::cout << count << std::endl;


    count = 0;
    // Check for:
    // .M.
    // MAS
    // .S.
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            if (get_char(contents, x+1, y) != 'M') {
                continue;
            }
            if (get_char(contents, x+1, y+2) != 'S') {
                continue;
            }
            if (get_char(contents, x, y+1) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y+1) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for:
    // .M.
    // SAM
    // .S.
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            if (get_char(contents, x+1, y) != 'M') {
                continue;
            }
            if (get_char(contents, x+1, y+2) != 'S') {
                continue;
            }
            if (get_char(contents, x, y+1) != 'S') {
                continue;
            }
            if (get_char(contents, x+2, y+1) != 'M') {
                continue;
            }
            count++;
        }
    }
    // Check for:
    // .S.
    // MAS
    // .M.
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            if (get_char(contents, x+1, y) != 'S') {
                continue;
            }
            if (get_char(contents, x+1, y+2) != 'M') {
                continue;
            }
            if (get_char(contents, x, y+1) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y+1) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for:
    // .S.
    // SAM
    // .M.
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            if (get_char(contents, x+1, y) != 'S') {
                continue;
            }
            if (get_char(contents, x+1, y+2) != 'M') {
                continue;
            }
            if (get_char(contents, x, y+1) != 'S') {
                continue;
            }
            if (get_char(contents, x+2, y+1) != 'M') {
                continue;
            }
            count++;
        }
    }

    // Check for:
    // M.S
    // .A.
    // M.S
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            if (get_char(contents, x, y) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y+2) != 'S') {
                continue;
            }
            if (get_char(contents, x, y+2) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for:
    // M.M
    // .A.
    // S.S
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            if (get_char(contents, x, y) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y+2) != 'S') {
                continue;
            }
            if (get_char(contents, x, y+2) != 'S') {
                continue;
            }
            if (get_char(contents, x+2, y) != 'M') {
                continue;
            }
            count++;
        }
    }
    // Check for:
    // S.S
    // .A.
    // M.M
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            if (get_char(contents, x, y) != 'S') {
                continue;
            }
            if (get_char(contents, x+2, y+2) != 'M') {
                continue;
            }
            if (get_char(contents, x, y+2) != 'M') {
                continue;
            }
            if (get_char(contents, x+2, y) != 'S') {
                continue;
            }
            count++;
        }
    }
    // Check for:
    // S.M
    // .A.
    // S.M
    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            if (get_char(contents, x, y) != 'S') {
                continue;
            }
            if (get_char(contents, x+2, y+2) != 'M') {
                continue;
            }
            if (get_char(contents, x, y+2) != 'S') {
                continue;
            }
            if (get_char(contents, x+2, y) != 'M') {
                continue;
            }
            count++;
        }
    }

    std::cout << count << std::endl;


    count = 0;

    for (int y=0; y < height; y++) {
        for (int x=0; x < width; x++) {
            if (get_char(contents, x+1, y+1) != 'A') {
                continue;
            }
            // if (get_char(contents, x+1, y) == 'M'
            //     && get_char(contents, x+1, y+2) == 'S'
            //     && get_char(contents, x, y+1) == 'M'
            //     && get_char(contents, x+2, y+1) == 'S') {
            //     count++;
            //     continue;
            // } else
            // if (get_char(contents, x+1, y) == 'M'
            //     && get_char(contents, x+1, y+2) == 'S'
            //     && get_char(contents, x, y+1) == 'S'
            //     && get_char(contents, x+2, y+1) == 'M') {
            //     count++;
            //     } else
            // if (get_char(contents, x+1, y) == 'S'
            //     && get_char(contents, x+1, y+2) == 'M'
            //     && get_char(contents, x, y+1) == 'M'
            //     && get_char(contents, x+2, y+1) == 'S') {
            //     count++;
            //     } else
            // if (get_char(contents, x+1, y) == 'S'
            //     && get_char(contents, x+1, y+2) == 'M'
            //     && get_char(contents, x, y+1) == 'S'
            //     && get_char(contents, x+2, y+1) == 'M'
            //     ) {
            //     count++;
            // }
            if (get_char(contents, x, y) == 'M'
                && get_char(contents, x+2, y+2) == 'S'
                && get_char(contents, x, y+2) == 'M'
                && get_char(contents, x+2, y) == 'S'
                ) {
                count++;
            } else
            if (get_char(contents, x, y) == 'M'
                && get_char(contents, x+2, y+2) == 'S'
                && get_char(contents, x, y+2) == 'S'
                && get_char(contents, x+2, y) == 'M'
                ) {
                count++;
                } else
            if (get_char(contents, x, y) == 'S'
                && get_char(contents, x+2, y+2) == 'M'
                && get_char(contents, x, y+2) == 'M'
                && get_char(contents, x+2, y) == 'S'
                ) {
                count++;
                } else
            if (get_char(contents, x, y) == 'S'
                && get_char(contents, x+2, y+2) == 'M'
                && get_char(contents, x, y+2) == 'S'
                && get_char(contents, x+2, y) == 'M'
                ) {
                count++;
                }
        }
    }

    std::cout << count << std::endl;

    return 0;
}