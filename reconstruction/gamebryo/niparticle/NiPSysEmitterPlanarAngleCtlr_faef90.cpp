// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfaef90 NiPSysEmitterPlanarAngleCtlr::dtor
// Adapted bodies: none
#include "NiPSysEmitterPlanarAngleCtlr_faef90.h"

// Emit the deleting destructor through the class constructor.
NiPSysEmitterPlanarAngleCtlr::NiPSysEmitterPlanarAngleCtlr() = default;
