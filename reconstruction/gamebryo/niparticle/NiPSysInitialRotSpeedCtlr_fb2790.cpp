// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfb2790 NiPSysInitialRotSpeedCtlr::dtor
// Adapted bodies: none
#include "NiPSysInitialRotSpeedCtlr_fb2790.h"

// Emit the deleting destructor through the class constructor.
NiPSysInitialRotSpeedCtlr::NiPSysInitialRotSpeedCtlr() = default;
