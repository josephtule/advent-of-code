#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {


    std::ifstream fid("sample.txt");
    std::string line;
    char opp, player;
    std::string pack1, pack2;
    while (std::getline(fid,line)) {
        size_t n = line.length(); 
        pack1 = line.substr(0,n/2);
        pack2 = line.substr(n/2,n);
    }
    std::cout << pack1 << std::endl << pack2 << std::endl;


    return 0;
}
