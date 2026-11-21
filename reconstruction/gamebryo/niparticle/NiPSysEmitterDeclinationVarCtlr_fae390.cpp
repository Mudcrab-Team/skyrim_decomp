// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfae390 NiPSysEmitterDeclinationVarCtlr::dtor
// Adapted bodies: none
#include "NiPSysEmitterDeclinationVarCtlr_fae390.h"

// Emit the deleting destructor through the class constructor.
NiPSysEmitterDeclinationVarCtlr::NiPSysEmitterDeclinationVarCtlr() = default;
