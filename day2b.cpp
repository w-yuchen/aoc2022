#include <iostream>
#include <string>

int check_points_cond(std::string s1, std::string s2) {
    if (s1 == "A" and s2 == "X") return 3; // lose against rock
    if (s1 == "A" and s2 == "Y") return 4; // draw with rock
    if (s1 == "A" and s2 == "Z") return 8; // win against rock
    if (s1 == "B" and s2 == "X") return 1; // lose against paper
    if (s1 == "B" and s2 == "Y") return 5; // paper
    if (s1 == "B" and s2 == "Z") return 9; // win, scissors
    if (s1 == "C" and s2 == "X") return 2; // lose, paper
    if (s1 == "C" and s2 == "Y") return 6; // draw, scissors 
    if (s1 == "C" and s2 == "Z") return 7; // win, rock
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
            // points += get_pts(opponent);
            points += check_points_cond(opponent, response);
        }
        catch(std::out_of_range const& ex) {
            break;
        }
    }

    std::cout << points << std::endl;
    return 0;
}
