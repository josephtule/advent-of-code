#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int pt1score(char opp, char player);
int pt2score(char opp, char result);

int main() {

    std::ifstream fid("input.txt");
    std::string line;
    char opp, player;
    int total1, total2; total1 = total2 = 0;
    while (std::getline(fid,line)) {
        opp = line[0];
        player = line.back();
        total1 += pt1score(opp, player);
        total2 += pt2score(opp, player);
    }
    // std::cout << i << std::endl;
    std::cout << "The total score is: " << total1 << std::endl;
    std::cout << "The total score is: " << total2 << std::endl;


    return 0;
}
int pt1score(char opp, char player) {
    int score = (int)player + 1 - (int)'X';
    int rule[3][3] = {{3,6,0},{0,3,6},{6,0,3}};
    score += rule[opp - 'A'][player-'X'];
    return score;
}

int pt2score(char opp, char result) {
    int score = (result - 'X') * 3;
    int rule[3][3] = {{3,1,2},{1,2,3},{2,3,1}};
    score += rule[opp - 'A'][result - 'X'];
    return score;
}
