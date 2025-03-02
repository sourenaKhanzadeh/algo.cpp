#ifndef _SORTING_H
#include <iostream>
#include <vector>

enum CMP { L = -2, LE = -1, E = 0, G = 1, GE = 2 };

bool should_swap(int a, int b, const CMP cmp) {
  switch (cmp) {
  case L:
    return a < b;
  case LE:
    return a <= b;
  case E:
    return a == b;
  case G:
    return a > b;
  case GE:
    return a >= b;
  default:
    return false;
  }
}

void printArr(const std::vector<int> &arr) {
  std::cout << "[";
  for (int num : arr) {
    std::cout << " " << num;
  }
  std::cout << "]";
  putchar('\n');
}

#endif
