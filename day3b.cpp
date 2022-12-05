#include <iostream>
#include <string>
#include <numeric>
#include <set>
#include <algorithm>
#include <vector>

int priority(char item) {
    if (item < '[') {
        return item - 38;
    } else {
        return item - 96;
    }
}

int main(int argc, char const *argv[])
{
    std::string s1;
    std::string s2;
    std::string s3;
    int p = 0;

    while (std::getline(std::cin, s1) && std::getline(std::cin, s2) && std::getline(std::cin, s3)) {
        std::set<char> c1(s1.begin(), s1.end());
        std::set<char> c2(s2.begin(), s2.end());
        std::set<char> c3(s3.begin(), s3.end());
        std::set<char> inter{};
        std::vector<char> res{};
        std::set_intersection(c1.begin(), c1.end(), c2.begin(), c2.end(), std::inserter(inter, inter.begin()));
        std::set_intersection(c3.begin(), c3.end(), inter.begin(), inter.end(), std::back_inserter(res));
        p += priority(res[0]);
    }
    
    std::cout << p << std::endl;
    return 0;
}
