/*!
    Solving: K'th smallest element in an unsorted array.

    This code can be run using the following command:
    ```
    g++ -std=c++17 k_smallest_unsorted_array.cpp && ./a.out
    ```
*/

#include <iostream>
#include <vector>
#include <random>

std::vector<int> generateUnsortedVector(int size = 100) {
    std::vector<int> unsorted;
    for (int i = 0; i < size; i++) {
        unsorted.push_back(i);
    }
    std::shuffle(unsorted.begin(), unsorted.end(), std::default_random_engine());
    return unsorted;
}

int main() {
    std::srand((unsigned) time(NULL));
    const int K = 1 + (rand() % 100);

    std::vector<int> array = generateUnsortedVector();
    std::sort(array.begin(), array.end());
    const int smallest = array.at(K - 1);

    std::cout << "With a K=" << K << ", the K'th smallest element is " << smallest << std::endl;
}
