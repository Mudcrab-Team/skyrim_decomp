// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfafb90 NiPSysFieldAttenuationCtlr::dtor
// Adapted bodies: none
#include "NiPSysFieldAttenuationCtlr_fafb90.h"

// Emit the deleting destructor through the class constructor.
NiPSysFieldAttenuationCtlr::NiPSysFieldAttenuationCtlr() = default;
