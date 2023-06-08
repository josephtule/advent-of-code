#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int firstnonnum(std::string str, char delim);

int main() {
    std::ifstream fid("input.txt");
    std::string line;

    std::string pack1, pack2;
    int score = 0;
    std::vector<std::string> strlist;
    
    std::vector<int> seg1, seg2;
    while (std::getline(fid,line)) {

        std::string str1, str2;
        int j = firstnonnum(line,',');
        str1 = line.substr(0,j); str2 = line.substr(j+1,line.length()-j);
        
        int i = firstnonnum(str1,'-'); int o = firstnonnum(str2,'-');
        int q = 0;
        for (int l = std::stoi(str1.substr(0,i)); l < std::stoi(str1.substr(i+1,str1.length()-i)); l++) {
            seg1.push_back(l);
            q++;
        }
        q = 0;
        for (int l = std::stoi(str2.substr(0,o)); l < std::stoi(str2.substr(o+1,str2.length()-o)); l++) {
            seg2.push_back(l);
            q++;
        }

         
    }   
}

int firstnonnum(std::string str,char delim) {
    int j;
    for (int k = 0; k < str.length(); k++) {
        if ((int)str[k] == (int)delim) {
            j = k;
            break;
        }
    }

    return j;
}
