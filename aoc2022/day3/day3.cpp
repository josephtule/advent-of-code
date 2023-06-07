#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int priority(int element);
void print_v(std::vector<int> &vec);
int checkWithin(std::string p1, std::string p2);
int commonin3strings(std::string p1, std::string p2, std::string p3);

int main() {


    std::ifstream fid("input.txt");
    std::string line;

    std::string pack1, pack2;
    int score = 0;
    int score2 = 0;
    std::vector<std::string> strlist;
    while (std::getline(fid,line)) {
        size_t n = line.length(); 
        pack1 = line.substr(0,n/2);
        pack2 = line.substr(n/2,n);
        score += checkWithin(pack1,pack2);
        strlist.push_back(line);
    }   
    std::cout << "Part 1 score: " << score << std::endl;

    
    for (int i = 0; i < strlist.size() - 2; i+=3) {
        // std::cout << strlist[i] << " " << strlist[i+1] << " " << strlist[i+2] << std::endl;
        score2 += commonin3strings(strlist[i],strlist[i+1],strlist[i+2]);
         }

    std::cout << "Part 2 score: " << score2 << std::endl;
    return 0;
}

int priority(int element) {
    int score;
    if (isupper(element)) {
        score = element - (int)'A' + 27;
    }
    else {
        score = element - (int)'a' + 1;
    }
    return (int)score;
}


void print_v(std::vector<int> &vec) {
    std::cout << "[";
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size()-1) {
            std::cout << vec[i] << "]";
        }
        else {
            std::cout << vec[i] << ", ";
        }
    }
    std::cout << std::endl;
}

int checkWithin(std::string p1, std::string p2) {
    int score;
    for (int i = 0; i < p1.length(); i++) {
        if(p2.find(p1[i])<p2.length()){ //to find +
            score = priority(p1[i]);
            break;
        }
        else {
            score = -1;
        }
    }

    return score;
}

int commonin3strings(std::string p1, std::string p2, std::string p3){
    int score2 = 0, score3 = 0;
    for(int i = 0; i < p1.length(); i++) {
        std::string subp1 = p1.substr(i,1);//  std::cout << subp1.length() << std::endl;
        score2 = checkWithin(subp1,p2);// std::cout << score2 << std::endl;
        score3 = checkWithin(subp1,p3); // std::cout << score3 << std::endl;
        if ((score2 == score3) & (score2 != -1 & score3 != -1)) {
            break;
        }
        else {
            score2 = score3 = 0;
        }
    }
    return score2;
}
