#include <iostream>
#include <string>

class Solution {
public:
    std::string intToRoman(int num) {
        std::string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        std::string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        std::string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        std::string ths[] = {"", "M", "MM", "MMM"};

        return ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    }
};

int main() {
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;

    Solution solution;
    std::string roman = solution.intToRoman(num);
    std::cout << "Roman numeral: " << roman << std::endl;

    return 0;
}
