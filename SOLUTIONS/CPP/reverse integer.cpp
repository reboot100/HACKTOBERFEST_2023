#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int sum = 0;
        while (x != 0) {
            int rem = x % 10;

            if ((sum > INT_MAX / 10) || (sum < INT_MIN / 10)) {
                return 0;
            }

            sum = sum * 10 + rem;
            x = x / 10;
        }

        return sum;
    }
};

int main() {
    int x;
    std::cout << "Enter an integer: ";
    std::cin >> x;

    Solution solution;
    int reversed = solution.reverse(x);

    std::cout << "Reversed integer: " << reversed << std::endl;

    return 0;
}
