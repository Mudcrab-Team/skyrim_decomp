// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: original reconstruction from the pinned image, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xeea710 NiObjectNET::LinkObject
// Adapted bodies: NiObjectNET::LinkObject follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niobjectnet.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/niobjectnet.cpp:81
// Adapted bodies: NiObjectNET::LinkObject follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/niobjectnet.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/niobjectnet.cpp:103
#include "NiObjectNET_eea710.h"

void NiObjectNET::LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);

    std::uint64_t count = stream.ReadLinkIDCount();
    SetExtraDataSize(static_cast<std::uint16_t>(count));
    if (static_cast<std::uint32_t>(count) != 0)
    {
        do
        {
            AddExtraData(static_cast<NiExtraData*>(stream.ReadLinkID()));
        } while (--count != 0);
    }

    auto* controller = static_cast<NiTimeController*>(stream.ReadLinkID());
    controllers = controller;
}
