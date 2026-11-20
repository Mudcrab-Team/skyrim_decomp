// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfb13d0 NiPSysGravityStrengthCtlr::dtor
// Adapted bodies: none
#include "NiPSysGravityStrengthCtlr_fb13d0.h"

// Emit the deleting destructor through the class constructor.
NiPSysGravityStrengthCtlr::NiPSysGravityStrengthCtlr() = default;
