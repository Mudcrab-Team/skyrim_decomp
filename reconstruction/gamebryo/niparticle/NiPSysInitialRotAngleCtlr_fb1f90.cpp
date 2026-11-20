// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfb1f90 NiPSysInitialRotAngleCtlr::dtor
// Adapted bodies: none
#include "NiPSysInitialRotAngleCtlr_fb1f90.h"

// Emit the deleting destructor through the class constructor.
NiPSysInitialRotAngleCtlr::NiPSysInitialRotAngleCtlr() = default;
