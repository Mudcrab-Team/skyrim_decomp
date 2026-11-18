// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// PathingRequestHide: EXE_RTTI
// 0x4f7d30 PathingRequestHide::Function4f7d30
#include "PathingRequestHide.h"
std::uint32_t PathingRequestHide::Function4f7d30() const {
  if (!PathingRequestHideTypeId) RegisterType(&PathingRequestHideTypeId, PathingRequestHideTypeName, nullptr);
  return PathingRequestHideTypeId;
}
