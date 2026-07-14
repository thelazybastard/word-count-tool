#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

bool checkForWord(std::string_view word, std::string_view subtext);
void hasFile(std::string filename, char command);
void hasNoFile(char command);

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[]) {
    if (argc < 2 || argc > 3)
        return 1;

    // check if user passed in file or not in case they want to check word count
    // with external tools like cat before passing in text to this tool
    checkForWord(argv[1], ".txt") ? hasFile(argv[2], argv[1][1])
                                  : hasNoFile(argv[1][1]);

    return 0;
}

bool checkForWord([[maybe_unused]] std::string_view text,
                  [[maybe_unused]] std::string_view subtext) {

    // for (int i = 0, len = text.size(); i < len; i++) {

    // }
    return true;
}

void hasFile(std::string filename, char command) {
    [[maybe_unused]] std::ifstream file(filename);

    if (!file.is_open())
        std::exit(1);

    int tracker{};

    std::string line{};
    char character{};
    std::string word{};

    switch (command) {
    case 'c':
        while (file.get(character)) {
            ++tracker;
        }
        break;
    case 'l':
        while (std::getline(file, line)) {
            ++tracker;
        }
        break;
    case 'w':
        while (file >> word) {
            ++tracker;
        };
        break;
    case 'm':
        while (file.get(character)) {
            ++tracker;
        }
        break;
    default:
        break;
    }

    std::cout << tracker << " " << filename << "\n";
}

void hasNoFile(char command) { std::cout << command; }