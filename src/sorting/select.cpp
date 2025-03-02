#include <cstddef>
#include <cstdlib>
#include <sorting/sorting.hpp>
#include <utility>

void ssort(std::vector<int> &arr, size_t _til, const CMP cmp = L) {
  size_t i = 0;
  while (i < _til) {
    int res = i;
    for (int j = i + 1; j < _til; j++) {
      if (should_swap(arr[j], arr[res], cmp))
        res = j;
    }
    std::swap(arr[i], arr[res]);
    i++;
  }
}

int main() {
  std::vector<int> arr = {10, 20, 30, 4, 5, 100, 2, 1};
  printArr(arr);
  ssort(arr, arr.size(), G);
  printArr(arr);

  return EXIT_SUCCESS;
}
