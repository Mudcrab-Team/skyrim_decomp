// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfa4540 NiPSysAirFieldAirFrictionCtlr::dtor
// Adapted bodies: none
#include "NiPSysAirFieldAirFrictionCtlr_fa4540.h"

// Emit the deleting destructor through the class constructor.
NiPSysAirFieldAirFrictionCtlr::NiPSysAirFieldAirFrictionCtlr() = default;
