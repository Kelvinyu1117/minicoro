#pragma once
#include "system/event/i_event_handler.hpp"
#include <atomic>

namespace io {
template<typename Poller> class Reactor
{
public:
  explicit Reactor(Poller &poller) : poller_(poller) {}

  bool run() noexcept
  {
    if (!running_.load(std::memory_order_acquire)) { return false; }

    while (running_.load(std::memory_order_acquire)) { poller_.poll(); }

    return true;
  }

  void stop() noexcept { running_.store(false, std::memory_order_release); }

  template<typename T> int add_event_handler(event::IEventHandler<T> *handler, uint32_t event_mask) noexcept
  {
    return poller_.add_event_handler(handler, event_mask);
  }

  template<typename T> int remove_event_handler(event::IEventHandler<T> *handler) noexcept
  {
    return poller_.remove_event_handler(handler);
  }

private:
  Poller &poller_;
  std::atomic_bool running_;
};

static_assert(std::atomic<bool>::is_always_lock_free);
}// namespace io
