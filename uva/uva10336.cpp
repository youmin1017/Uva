#include<bits/stdc++.h>

void bfs(std::vector<std::string>& map, const char& t, int i, int j, int row, int col);

bool cmp(std::pair<char, int>& a,
         std::pair<char, int>& b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main() {
    int N;
    std::cin >> N;

    for(int w=1; w <= N; ++w) {
        int row, col;
        std::cin >> row >> col;
        std::vector<std::string> map(row, "");
        std::map<char, int> record;

        for(int i=0; i < row; ++i) {
            // std::cout << i << std::endl;
            std::cin >> map[i];
        }

        for(int i=0; i < row; ++i) {
            for(int j=0; j < col; ++j) {
                char c = map[i][j];
                if(c != 0) {
                    bfs(map, c, i, j, row, col);
                    record[c]++;
                }
            }
        }

        std::vector<std::pair<char, int>> res;
        std::copy(record.begin(), record.end(),
            std::back_inserter<std::vector<std::pair<char, int>>>(res));

        std::sort(res.begin(), res.end(), cmp);
        
        std::cout << "World #" << w << std::endl;
        for(auto& item : res) {
            std::cout << item.first << ": " << item.second << std::endl;
        }
    }
}

void bfs(std::vector<std::string>& map, const char& c, int i, int j, int row, int col) {
    if(i < 0 or i >= row or j < 0 or j >= col)
        return;
    if(map[i][j] != c) 
        return; 
    
    map[i][j] = 0;
    bfs(map, c, i+1, j, row, col);
    bfs(map, c, i-1, j, row, col);
    bfs(map, c, i, j+1, row, col);
    bfs(map, c, i, j-1, row, col);
}