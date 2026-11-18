// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// PathingRequestFly: EXE_RTTI
// 0x4f5400 PathingRequestFly::Function4f5400
#include "PathingRequestFly.h"
std::uint32_t PathingRequestFly::Function4f5400() const {
  if (!PathingRequestFlyTypeId) RegisterType(&PathingRequestFlyTypeId, PathingRequestFlyTypeName, nullptr);
  return PathingRequestFlyTypeId;
}
