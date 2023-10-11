#include <iostream>
#include <vector>

int binarySearch(std::vector<int> arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == target) {
            return mid; // Element found, return its index
        } else if (arr[mid] < target) {
            left = mid + 1; // Adjust the left boundary
        } else {
            right = mid - 1; // Adjust the right boundary
        }
    }
    
    return -1; // Element not found
}

int main() {
    int n, target;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;
    
    std::vector<int> arr(n);
    std::cout << "Enter sorted elements: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }
    
    std::cout << "Enter the target element to search for: ";
    std::cin >> target;
    
    int result = binarySearch(arr, target);
    
    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }
    
    return 0;
}
