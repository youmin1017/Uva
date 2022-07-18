#include<iostream>

int main() {
    int N, i, j;
    while(std::cin >> N >> i >> j) {
        int ans(0);
        do {
            ans++;
            i = (i+i%2)/2;
            j = (j+j%2)/2;
        } while(i != j);
        std::cout << ans << std::endl;
    }
}