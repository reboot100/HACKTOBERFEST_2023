#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
    MinStack() {
        
    }
    
    void push(int val) {
        if (s.empty()) {
            s.push({val, val});
        } else {
            int currentMin = min(val, getMin());
            s.push({val, currentMin});
        }
    }
    
    void pop() {
        if (!s.empty()) {
            s.pop();
        }
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }

private:
    stack<pair<int, int>> s;
};

int main() {
    MinStack minStack;
    cout << "Enter the number of operations: ";
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int choice;
        cin >> choice;
        if (choice == 1) {
            int val;
            cin >> val;
            minStack.push(val);
        } else if (choice == 2) {
            minStack.pop();
        } else if (choice == 3) {
            cout << "Top: " << minStack.top() << endl;
        } else if (choice == 4) {
            cout << "Min: " << minStack.getMin() << endl;
        }
    }

    return 0;
}
