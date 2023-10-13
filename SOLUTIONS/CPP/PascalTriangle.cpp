#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> pascal(numRows);
        for (int i = 0; i < numRows; i++) {
            pascal[i].resize(i + 1);
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    pascal[i][j] = 1;
                } else {
                    pascal[i][j] = pascal[i - 1][j] + pascal[i - 1][j - 1];
                }
            }
        }
        return pascal;
    }
};

int main() {
    Solution solution;
    int numRows = 5; 
    std::vector<std::vector<int>> result = solution.generate(numRows);

    for (const std::vector<int>& row : result) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
