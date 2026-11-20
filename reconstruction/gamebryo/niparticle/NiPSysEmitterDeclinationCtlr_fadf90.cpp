// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfadf90 NiPSysEmitterDeclinationCtlr::dtor
// Adapted bodies: none
#include "NiPSysEmitterDeclinationCtlr_fadf90.h"

// Emit the deleting destructor through the class constructor.
NiPSysEmitterDeclinationCtlr::NiPSysEmitterDeclinationCtlr() = default;
