// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfa4950 NiPSysAirFieldInheritVelocityCtlr::dtor
// Adapted bodies: none
#include "NiPSysAirFieldInheritVelocityCtlr_fa4950.h"

// Emit the deleting destructor through the class constructor.
NiPSysAirFieldInheritVelocityCtlr::NiPSysAirFieldInheritVelocityCtlr() = default;
