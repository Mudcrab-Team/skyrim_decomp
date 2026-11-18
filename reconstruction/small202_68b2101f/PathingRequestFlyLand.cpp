// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// PathingRequestFlyLand: EXE_RTTI
// 0x4f6ed0 PathingRequestFlyLand::Function4f6ed0
#include "PathingRequestFlyLand.h"
std::uint32_t PathingRequestFlyLand::Function4f6ed0() const {
  if (!PathingRequestFlyLandTypeId) RegisterType(&PathingRequestFlyLandTypeId, PathingRequestFlyLandTypeName, nullptr);
  return PathingRequestFlyLandTypeId;
}
