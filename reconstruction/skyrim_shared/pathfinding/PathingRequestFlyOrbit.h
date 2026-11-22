// Source exposure: mixed (pinned image listing and authorized sibling hints).
// Code origin: original declarations and the cited sibling adaptation.
// Sibling source: fo4-private@1b765c70 src/Shared/Pathfinding/Searches/PathingRequestFlyOrbit.cpp:67
// PathingRequestFlyOrbit, PathingRequestFlyOrbit::GetType: SIBLING(fo4-private@1b765c70, author-permission)
// PathingRequestFlyOrbit_typeCRC, PathingRequestFlyOrbit_typeName, GenerateTypeCRC: STANDIN GUESS(low)
// NiPoint3 layout: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include <cstdint>
#include "generated/crashlogger_pdb/types/NiPoint3.h"
class PathingRequestFlyOrbit {
public:
    unsigned int GetType() const;
    void SetOrbitPoint(const NiPoint3& a_point);
    NiPoint3& GetOrbitPoint(NiPoint3& a_out) const;

private:
    std::uint8_t unknown00[0x130];
    NiPoint3 orbitPoint;
};
