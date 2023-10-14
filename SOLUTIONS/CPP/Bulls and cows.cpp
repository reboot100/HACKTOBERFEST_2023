#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> m;
        for (int i = 0; i < secret.size(); i++) {
            m[secret[i]]++;
        }
        int bulls = 0;
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            }
        }
        int count = 0;
        for (int i = 0; i < guess.size(); i++) {
            if (m[guess[i]] == 0) {
                count++;
            } else {
                m[guess[i]]--;
            }
        }
        return to_string(bulls) + 'A' + to_string(secret.size() - bulls - count) + 'B';
    }
};

int main() {
    string secret, guess;
    cout << "Enter secret: ";
    cin >> secret;
    cout << "Enter guess: ";
    cin >> guess;

    Solution solution;
    string result = solution.getHint(secret, guess);
    cout << result << endl;

    return 0;
}
