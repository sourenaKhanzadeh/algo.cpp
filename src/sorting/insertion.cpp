#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

void isort(std::vector<int> arr, size_t _til) {}

void printArr(std::vector<int> arr) {
  std::cout << "[";
  for (int num : arr) {
    std::cout << " " << num;
  }
  std::cout << "]";
}

int main() {
  std::vector<int> arr = {10, 1, 20, 30, 2, 3, 4, 5};
  printArr(arr);
  isort(arr, arr.size());
  printArr(arr);
  return EXIT_SUCCESS;
}
