#include <iostream>
#include <string>
#include <numeric>

int get_pts(std::string s) {
    if (s == "X") return 1;
    if (s == "Y") return 2;
    if (s == "Z") return 3;
    return 0;
}

int check_win(std::string s1, std::string s2) {
    if (s1 == "A" and s2 == "X") return 3;
    if (s1 == "A" and s2 == "Y") return 6;
    if (s1 == "A" and s2 == "Z") return 0;
    if (s1 == "B" and s2 == "X") return 0;
    if (s1 == "B" and s2 == "Y") return 3;
    if (s1 == "B" and s2 == "Z") return 6;
    if (s1 == "C" and s2 == "X") return 6;
    if (s1 == "C" and s2 == "Y") return 0;
    if (s1 == "C" and s2 == "Z") return 3;
    return 0;
}

int main(int argc, char const *argv[])
{
    int points = 0;
    for (std::string line; std::getline(std::cin, line);) {
        try
        {
            auto opponent = line.substr(0, 1);
            auto response = line.substr(2, 1);
            points += get_pts(response);
            points += check_win(opponent, response);
        }
        catch(std::out_of_range const& ex) {
            break;
        }
    }

    std::cout << points << std::endl;
    return 0;
}
