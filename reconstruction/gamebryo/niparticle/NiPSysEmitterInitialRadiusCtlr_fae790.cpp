// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfae790 NiPSysEmitterInitialRadiusCtlr::dtor
// Adapted bodies: none
#include "NiPSysEmitterInitialRadiusCtlr_fae790.h"

// Emit the deleting destructor through the class constructor.
NiPSysEmitterInitialRadiusCtlr::NiPSysEmitterInitialRadiusCtlr() = default;
