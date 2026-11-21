// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfb03a0 NiPSysFieldMaxDistanceCtlr::dtor
// Adapted bodies: none
#include "NiPSysFieldMaxDistanceCtlr_fb03a0.h"

// Emit the deleting destructor through the class constructor.
NiPSysFieldMaxDistanceCtlr::NiPSysFieldMaxDistanceCtlr() = default;
