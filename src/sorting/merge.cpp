#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <sorting/sorting.hpp>
#include <vector>

// In-place merge function (optimized)
void merge(std::vector<int> &arr, size_t start, size_t mid, size_t end,
           CMP cmp) {
  std::vector<int> left(arr.begin() + start, arr.begin() + mid);
  std::vector<int> right(arr.begin() + mid, arr.begin() + end);

  size_t i = 0, j = 0, k = start;

  while (i < left.size() && j < right.size()) {
    if (should_swap(left[i], right[j], cmp)) {
      arr[k++] = std::move(left[i++]);
    } else {
      arr[k++] = std::move(right[j++]);
    }
  }

  while (i < left.size())
    arr[k++] = std::move(left[i++]);
  while (j < right.size())
    arr[k++] = std::move(right[j++]);
}

// Recursive Merge Sort function (works on the same vector)
void helper_msort(std::vector<int> &arr, size_t start, size_t end, CMP cmp) {
  if (end - start <= 1)
    return;

  size_t mid = start + (end - start) / 2;
  helper_msort(arr, start, mid, cmp);
  helper_msort(arr, mid, end, cmp);
  merge(arr, start, mid, end, cmp);
}

// Main Merge Sort function (calls recursive function)
void msort(std::vector<int> &arr, CMP cmp = L) {
  if (arr.empty())
    return;
  helper_msort(arr, 0, arr.size(), cmp);
}

// Main function
int main() {
  std::vector<int> arr = {203, 10, 20, 30, 1, 2, 3, -1};
  std::cout << "Original array: ";
  printArr(arr);

  msort(arr, L); // Sort in ascending order

  std::cout << "Sorted array: ";
  printArr(arr);

  return EXIT_SUCCESS;
}
