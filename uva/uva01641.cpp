#include<iostream>
#include<string>

int main() {
    int h, w;
    std::string row;
    
    while(std::cin >> h >> w) {
        double sum=0;
        for(int i=0; i < h; i++) {
            std::cin >> row;
            bool flag = false;
            for(int j=0; j < w; ++j) {
                if(row[j] == '\\' || row[j] == '/') {
                    flag = !flag;
                    sum += 0.5;
                } else if(flag && row[j] == '.') {
                    sum += 1.0;
                }
            }
        }
        std::cout << static_cast<int>(sum) << std::endl;
    }
}