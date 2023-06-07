#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {

  std::ifstream fid;
  fid.open("input.txt");
  std::string line;
  std::vector<double> elfscore;
  double score = 0;

  if (fid.is_open()) {
    while (fid) {
      std::getline(fid, line);
      if (line.empty()) {
        elfscore.push_back(score);
        // std::cout << score << std::endl;
        score = 0;
      } else {
        score += std::stod(line);
      }
    }
  } else {
    std::cout << "Couldn't open file\n";
  }
  size_t len = elfscore.size();
  std::sort(elfscore.begin(), elfscore.end());
  std::cout << "Top 3 Elves: [";
  for (int i = 0; i < 3; i++) {
    if (i != 2) {
      std::cout << elfscore[len - i - 1] << ", ";
    } else {
      std::cout << elfscore[len - i - 1] << "]";
    }
  }
  std::cout << std::endl;
  std::cout << "Top 3 Combined: "
            << elfscore[len - 1] + elfscore[len - 2] + elfscore[len - 3]
            << std::endl;
  return 0;
}
