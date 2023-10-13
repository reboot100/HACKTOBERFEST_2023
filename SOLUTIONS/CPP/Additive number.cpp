#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        string first, sec, third;
        int n = num.size();

        if (n <= 2) {
            return false;
        } else if (n == 3) {
            if (num[0] - '0' + num[1] - '0' == num[2] - '0') {
                return true;
            } else {
                return false;
            }
        } else {
            for (int i = 1; i <= n / 2; i++) {
                for (int j = i + 1; j < n; j++) {
                    string first = num.substr(0, i);
                    string sec = num.substr(i, j - i);

                    if ((first.size() > 1 && first[0] == '0') || (sec.size() > 1 && sec[0] == '0'))
                        continue;

                    long long num1 = stoll(first);
                    long long num2 = stoll(sec);

                    int k = j;
                    while (k < n) {
                        num2 = num1 + num2;
                        first = to_string(num2);

                        if (num.compare(k, first.size(), first) != 0)
                            break;

                        k += first.size();
                        num1 = stoll(sec);
                        sec = first;

                        if (k == n)
                            return true;
                    }
                }
            }

            return false;
        }
    }
};

int main() {
    string num;
    cout << "Enter a number: ";
    cin >> num;

    Solution solution;
    bool result = solution.isAdditiveNumber(num);

    if (result) {
        cout << "The entered number is an additive number." << endl;
    } else {
        cout << "The entered number is not an additive number." << endl;
    }

    return 0;
}
