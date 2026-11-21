// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfb2b90 NiPSysInitialRotSpeedVarCtlr::dtor
// Adapted bodies: none
#include "NiPSysInitialRotSpeedVarCtlr_fb2b90.h"

// Emit the deleting destructor through the class constructor.
NiPSysInitialRotSpeedVarCtlr::NiPSysInitialRotSpeedVarCtlr() = default;
