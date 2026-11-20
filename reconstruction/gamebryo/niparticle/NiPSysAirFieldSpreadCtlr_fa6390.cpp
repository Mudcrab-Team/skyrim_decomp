// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfa6390 NiPSysAirFieldSpreadCtlr::dtor
// Adapted bodies: none
#include "NiPSysAirFieldSpreadCtlr_fa6390.h"

// Emit the deleting destructor through the class constructor.
NiPSysAirFieldSpreadCtlr::NiPSysAirFieldSpreadCtlr() = default;
