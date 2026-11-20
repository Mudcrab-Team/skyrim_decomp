// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfb58a0 NiPSysModifierActiveCtlr::dtor
// Adapted bodies: none
#include "NiPSysModifierActiveCtlr_fb58a0.h"

// Emit the deleting destructor through the class constructor.
NiPSysModifierActiveCtlr::NiPSysModifierActiveCtlr() = default;
