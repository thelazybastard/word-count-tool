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
    if (argc == 3 && checkForWord(argv[2], "txt")) {
        hasFile(argv[2], argv[1][1]);
    } else {
        hasNoFile(argv[1][1]);
    }

    return 0;
}

bool checkForWord(std::string_view text, std::string_view subtext) {

    if (text.contains(subtext))
        return true;

    return false;
}

void hasFile(std::string filename, char command) {
    [[maybe_unused]] std::ifstream file(filename);

    if (!file.is_open())
        std::exit(1);

    long tracker{};

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
        while (file.get(character)) {
            ++tracker;
        }
        tracker = 0;
        std::cout << tracker;
        while (std::getline(file, line)) {
            ++tracker;
        }
        tracker = 0;
        std::cout << tracker;
        while (file >> word) {
            ++tracker;
        };
        std::cout << tracker << filename << "\n";
        std::exit(0);
        break;
    }

    std::cout << tracker << " " << filename << "\n";
}

void hasNoFile(char command) {
    long tracker{};

    std::string line{};
    std::string word{};

    switch (command) {
    case 'c':
        while (std::getchar() != EOF) {
            ++tracker;
        }
        break;
    case 'l':
        while (std::getline(std::cin, line)) {
            ++tracker;
        }
        break;
    case 'w':
        while (std::cin >> word) {
            ++tracker;
        };
        break;
    case 'm':
        while (std::getchar() != EOF) {
            ++tracker;
        }
        break;
    default:
        while (std::getchar()) {
            ++tracker;
        }
        std::cout << tracker;
        tracker = 0;
        while (std::getline(std::cin, line)) {
            ++tracker;
        }
        std::cout << tracker;
        tracker = 0;
        while (std::cin >> word) {
            ++tracker;
        };
        std::cout << tracker << "\n";
        std::exit(0);
        break;
    }

    std::cout << tracker << "\n";
}