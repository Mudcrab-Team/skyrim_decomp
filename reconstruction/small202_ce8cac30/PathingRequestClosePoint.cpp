// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// PathingRequestClosePoint: EXE_RTTI
// 0x4f2420 PathingRequestClosePoint::Function4f2420
#include "PathingRequestClosePoint.h"
std::uint32_t PathingRequestClosePoint::Function4f2420() const {
  if (!PathingRequestClosePointTypeId) RegisterType(&PathingRequestClosePointTypeId, PathingRequestClosePointTypeName, nullptr);
  return PathingRequestClosePointTypeId;
}
