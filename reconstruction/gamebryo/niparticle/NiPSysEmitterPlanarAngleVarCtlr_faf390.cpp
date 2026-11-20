// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfaf390 NiPSysEmitterPlanarAngleVarCtlr::dtor
// Adapted bodies: none
#include "NiPSysEmitterPlanarAngleVarCtlr_faf390.h"

// Emit the deleting destructor through the class constructor.
NiPSysEmitterPlanarAngleVarCtlr::NiPSysEmitterPlanarAngleVarCtlr() = default;
