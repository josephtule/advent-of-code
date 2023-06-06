#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {


    std::ifstream fid;
    fid.open("C:\\Users\\N13617\\OneDrive - NGC\\Documents\\CPP\\aoc\\day1\\input.txt");
    std::string line;
    std::vector<double> elfscore;
    double score = 0;

    if (fid.is_open()) {
        while (fid) {
            std::getline (fid,line);
            if (line.empty()) {
                elfscore.push_back(score);
                // std::cout << score << std::endl;
                score = 0;
            }
            else {
            score += std::stod(line);
            }
        }
    }
    else
    {
        std::cout << "Couldn't open file\n";
    }
    size_t len = elfscore.size(); 
    std::sort(elfscore.begin(), elfscore.end());
    std::cout << elfscore[len-1] << std::endl;
    std::cout << elfscore[len-2] << std::endl;
    std::cout << elfscore[len-3] << std::endl;
    std::cout << elfscore[len-1] + elfscore[len-2] + elfscore[len-3] << std::endl;
    return 0;
}
