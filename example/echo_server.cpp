#include <execution/executor.hpp>
#include <iostream>

void start() { std::cout << "Hello, World\n"; }

int main() {
  using namespace minicoro;

  execution::Executor executor;

  executor.run([]() { start(); });
  return 0;
}
