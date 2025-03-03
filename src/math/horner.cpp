#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ostream>

double horner(int *poly, double x, size_t _len) {
  double result = poly[0];
  for (size_t i = 1; i < _len; i++) {
    result = poly[i] + x * result;
  }
  return result;
}

int main() {
  int poly[5] = {0, 0, 2, 2, 9};
  std::cout << horner(poly, 2, 5) << std::endl;
  return EXIT_SUCCESS;
}
