// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: original reconstruction from the pinned image, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xef7f80 NiTimeController::LinkObject
// Adapted bodies: NiTimeController::LinkObject follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nitimecontroller.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nitimecontroller.cpp:59
// Adapted bodies: NiTimeController::LinkObject follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/nitimecontroller.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/nitimecontroller.cpp:61
#include "NiTimeController_ef7f80.h"

void NiTimeController::LinkObject(NiStream& stream)
{
    auto* nextController = static_cast<NiTimeController*>(stream.ReadLinkID());
    next = nextController;
    target = static_cast<NiObjectNET*>(stream.ReadLinkID());
}
