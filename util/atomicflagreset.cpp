#include "atomicflagreset.h"

QtCommon2::AtomicFlagReset::AtomicFlagReset(std::atomic_flag *flag, std::memory_order memoryOrder)
{
  this->flag = flag;
  this->memoryOrder = memoryOrder;
}

QtCommon2::AtomicFlagReset::~AtomicFlagReset()
{
  flag->clear(memoryOrder);
}
