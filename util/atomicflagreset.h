#pragma once

#include <atomic>
#include <qtcommon2_global.h>
namespace QtCommon2{
  class QTCOMMON2SHARED_EXPORT AtomicFlagReset
  {
    std::atomic_flag* flag;
    std::memory_order memoryOrder;
  public:
    AtomicFlagReset(std::atomic_flag* flag,std::memory_order memoryOrder = std::memory_order_seq_cst);
    ~AtomicFlagReset();
  };

}
