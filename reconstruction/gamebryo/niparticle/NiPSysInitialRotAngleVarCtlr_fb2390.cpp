// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfb2390 NiPSysInitialRotAngleVarCtlr::dtor
// Adapted bodies: none
#include "NiPSysInitialRotAngleVarCtlr_fb2390.h"

// Emit the deleting destructor through the class constructor.
NiPSysInitialRotAngleVarCtlr::NiPSysInitialRotAngleVarCtlr() = default;
