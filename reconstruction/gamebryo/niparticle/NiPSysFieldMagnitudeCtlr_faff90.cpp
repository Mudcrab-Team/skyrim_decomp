// Source exposure: binary-analysis (pinned image).
// Code origin: original reconstruction using the observed cleanup calls.
// 0xfaff90 NiPSysFieldMagnitudeCtlr::dtor
// Adapted bodies: none
#include "NiPSysFieldMagnitudeCtlr_faff90.h"

// Emit the deleting destructor through the class constructor.
NiPSysFieldMagnitudeCtlr::NiPSysFieldMagnitudeCtlr() = default;
