#include <iostream>
#include <vector>

using namespace std;

class NumArray {
public:
    vector<int> st;
    vector<int> vals;
    int n;

    NumArray(vector<int>& nums) : n(nums.size()), st(4 * nums.size(), 0) {
        vals = nums;
        build(0, 0, n - 1);
    }

    void build(int node, int start, int end) {
        if (start == end) {
            st[node] = vals[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node + 1, start, mid);
        build(2 * node + 2, mid + 1, end);
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void updateST(int node, int start, int end, int index, int val) {
        if (start == end) {
            st[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid) updateST(2 * node + 1, start, mid, index, val);
        else updateST(2 * node + 2, mid + 1, end, index, val);
        st[node] = st[2 * node + 1] + st[2 * node + 2];
    }

    void update(int index, int val) {
        updateST(0, 0, n - 1, index, val);
        vals[index] = val;
    }

    int sumRangeHelper(int node, int start, int end, int left, int right) {
        if (start > right || end < left) return 0;
        if (start >= left && end <= right) return st[node];
        int mid = (start + end) / 2;
        int leftSum = sumRangeHelper(2 * node + 1, start, mid, left, right);
        int rightSum = sumRangeHelper(2 * node + 2, mid + 1, end, left, right);
        return leftSum + rightSum;
    }

    int sumRange(int left, int right) {
        return sumRangeHelper(0, 0, n - 1, left, right);
    }
};

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> nums(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    NumArray* obj = new NumArray(nums);

    int index, val;
    cout << "Enter the index and value for the update operation: ";
    cin >> index >> val;
    obj->update(index, val);

    int left, right;
    cout << "Enter the left and right indices for the sumRange operation: ";
    cin >> left >> right;
    int param_2 = obj->sumRange(left, right);

    cout << "Result of sumRange operation: " << param_2 << endl;

    delete obj;

    return 0;
}
