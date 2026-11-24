// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: original reconstruction from the pinned image, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xefa110 NiGeometryData::LinkObject
// Adapted bodies: NiGeometryData::LinkObject follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nigeometrydata.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/nigeometrydata.cpp:43
// Adapted bodies: NiGeometryData::LinkObject follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/nigeometrydata.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/nigeometrydata.cpp:58
#include "NiGeometryData_efa110.h"

void NiGeometryData::LinkObject(NiStream& stream)
{
    NiObject::LinkObject(stream);
    auto* additional = static_cast<NiAdditionalGeometryData*>(stream.ReadLinkID());
    additionalGeomData = additional;
}
