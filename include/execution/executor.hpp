#pragma once

#include <execution/execution_policy.hpp>
#include <type_traits>
namespace minicoro::execution {
template <ExecutionPolicy TPolicy> class Executor {
  template <typename F> void run(F &&callable) { callable(); }
};
} // namespace minicoro::execution
