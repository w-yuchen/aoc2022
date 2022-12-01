#include <iostream>
#include <string>
#include <numeric>
#include <queue>
#include <vector>

int main(int argc, char const *argv[])
{

    // day 1a
    // int c = 1;

    // day 1b;
    int c = 3;

    int cur_sum = 0;
    bool nl = false;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    
    for (std::string line; std::getline(std::cin, line);) {
        try
        {
            cur_sum += std::stoi(line);
            nl = false;
        }
        catch(std::invalid_argument const& ex)
        {
            q.push(cur_sum);
            if (q.size() > 3) {
                q.pop();
            }
            
            // max = std::max(max, cur_sum);
            cur_sum = 0;
            if (nl) {
                break;
            } else {
                nl = true;
                continue;
            }
        }
        
    }
    int max = 0;
    std::cout << q.size() <<std::endl;
    for (int i = 0; i < c; i++) {
        max += q.top();
        if (q.empty()) {
            continue;
        }
        q.pop();
    }
    std::cout << max << std::endl;
    return 0;
}
