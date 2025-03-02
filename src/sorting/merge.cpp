#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <sorting/sorting.hpp>
#include <vector>

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right,
                       const CMP cmp = L);

std::vector<int> helper_msort(std::vector<int> &arr, size_t start, size_t end,
                              const CMP cmp = L);
std::vector<int> msort(std::vector<int> &arr, size_t _til, const CMP cmp = L) {
  if (arr.empty())
    return {};
  return helper_msort(arr, 0, _til, cmp);
}

// Recursive Merge Sort function
std::vector<int> helper_msort(std::vector<int> &arr, size_t start, size_t end,
                              const CMP cmp) {
  if (end - start <= 1) {
    return {arr[start]};
  }

  size_t mid = start + (end - start) / 2;
  std::vector<int> left = helper_msort(arr, start, mid, cmp);
  std::vector<int> right = helper_msort(arr, mid, end, cmp);

  return merge(left, right, cmp);
}

std::vector<int> merge(std::vector<int> &left, std::vector<int> &right,
                       const CMP cmp) {
  size_t l = 0, r = 0;
  std::vector<int> res;

  while (l < left.size() && r < right.size()) {
    if (should_swap(left[l], right[r], cmp)) {
      res.push_back(left[l]);
      l++;
    } else {
      res.push_back(right[r]);
      r++;
    }
  }

  while (l < left.size()) {
    res.push_back(left[l]);
    l++; // Fix: Increment l
  }

  while (r < right.size()) {
    res.push_back(right[r]);
    r++; // Fix: Increment r
  }

  return res;
}
int main() {
  std::vector<int> arr = {203, 10, 20, 30, 1, 2, 3, -1};
  printArr(arr);
  std::vector<int> v = msort(arr, arr.size(), GE);
  printArr(v);
  return EXIT_SUCCESS;
}
