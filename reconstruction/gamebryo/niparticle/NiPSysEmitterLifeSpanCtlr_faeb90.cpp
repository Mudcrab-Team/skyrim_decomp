// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfaeb90 NiPSysEmitterLifeSpanCtlr::dtor
// Adapted bodies: none
#include "NiPSysEmitterLifeSpanCtlr_faeb90.h"

// Emit the deleting destructor through the class constructor.
NiPSysEmitterLifeSpanCtlr::NiPSysEmitterLifeSpanCtlr() = default;
