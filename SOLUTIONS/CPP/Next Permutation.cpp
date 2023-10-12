#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
   void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    
    int i = n - 1;
    while (i > 0 && nums[i-1] >= nums[i])
        i--;
    
    if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    int j = n - 1;
    while (nums[j] <= nums[i-1])
        j--;
    
    swap(nums[i-1], nums[j]);
    
    reverse(nums.begin() + i, nums.end());
}
};

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution solution;
    solution.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
