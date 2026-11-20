// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfaf790 NiPSysEmitterSpeedCtlr::dtor
// Adapted bodies: none
#include "NiPSysEmitterSpeedCtlr_faf790.h"

// Emit the deleting destructor through the class constructor.
NiPSysEmitterSpeedCtlr::NiPSysEmitterSpeedCtlr() = default;
