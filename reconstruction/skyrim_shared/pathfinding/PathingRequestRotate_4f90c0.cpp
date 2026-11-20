// Origin: original reconstruction; no sibling source used.
// Source exposure: mixed (local binary analysis and pinned public declarations).
// PathingRequestRotate: EXE_RTTI
// 0x4f90c0 PathingRequestRotate::Function4f90c0
#include "PathingRequestRotate_4f90c0.h"
std::uint32_t PathingRequestRotate::Function4f90c0() const {
  if (!PathingRequestRotateTypeId) RegisterType(&PathingRequestRotateTypeId, PathingRequestRotateTypeName, nullptr);
  return PathingRequestRotateTypeId;
}
