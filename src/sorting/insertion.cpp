#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <sorting/sorting.hpp>
#include <utility>

void isort(std::vector<int> &arr, size_t _til, const CMP cmp = L) {
  for (size_t i = 1; i < _til; i++) {
    for (size_t j = 0; j < i; j++) {
      if (should_swap(arr[i], arr[j], cmp))
        std::swap(arr[i], arr[j]);
    }
  }
}

int main() {
  std::vector<int> arr = {10, 1, 20, 30, 2, 3, 4, 5};
  printArr(arr);
  isort(arr, arr.size(), GE);
  printArr(arr);
  return EXIT_SUCCESS;
}
