#include <iostream>
#include <string>
#include <numeric>
#include <map>

int priority(char item) {
    if (item < '[') {
        return item - 38;
    } else {
        return item - 96;
    }
}

int main(int argc, char const *argv[])
{
    int p = 0;

    for (std::string line; std::getline(std::cin, line);) {
        if (line.length() == 0) {
            break;
        }
        std::map<char, int> m{};
        int l = line.length();
        int half = l / 2;
        for (int i = 0; i < half; i++) {
            auto c = line[i];
            m[c] = priority(c);
        }
        for (int i = half; i < l; i++) {
            auto c = line[i];
            if (m.contains(c)) {
                p += m[c];
                m.erase(c);
            }
        }
    }

    std::cout << p << std::endl;
    return 0;
}
