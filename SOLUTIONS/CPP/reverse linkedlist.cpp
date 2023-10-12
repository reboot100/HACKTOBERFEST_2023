#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* curr = head;

    while (curr != nullptr) {
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

int main() {
    ListNode* head = nullptr;
    int n, val;

    using namespace std; // Adding the 'using namespace std' directive

    cout << "Enter the number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter the value for node " << i + 1 << ": ";
        cin >> val;
        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
    }

    ListNode* reversed = reverseList(head);

    cout << "Reversed list: ";
    while (reversed != nullptr) {
        cout << reversed->val << " ";
        reversed = reversed->next;
    }

    cout << endl;

    return 0;
}
