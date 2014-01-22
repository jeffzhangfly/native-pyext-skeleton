#include <cstdlib>


void* do_something(size_t sz) {
  return malloc(sizeof(char) * sz);
}
