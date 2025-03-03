#include <cstddef>
#include <cstdlib>
#include <sorting/sorting.hpp>
#include <utility>

void bsort(std::vector<int> &arr, size_t _til, const CMP cmp = L) {
  for (size_t i = 1; i < _til; i++) {
    for (size_t j = 0; j < i; j++) {
      if (should_swap(arr[i], arr[j], cmp)) {
        std::swap(arr[i], arr[j]);
      }
    }
  }
}

int main() {
  std::vector<int> arr = {-203, 10, 20, 30, 1, 2, 3, -1};
  std::cout << "Original array: ";
  printArr(arr);

  bsort(arr, arr.size());
  std::cout << "Sorted array: ";
  printArr(arr);
  return EXIT_SUCCESS;
}
