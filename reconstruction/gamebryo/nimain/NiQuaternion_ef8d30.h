// Source exposure: mixed (pinned image and sibling study reference).
// Code origin: original reconstruction informed by the anonymous sibling study reference.
// NiQuaternion layout: CRASHLOGGER_PDB(59818@2026.10.24)
// UnitInverse: SIBLING(fo4-private@1b765c70, author-permission)
#pragma once

struct NiQuaternion
{
    float w, x, y, z;
    static NiQuaternion UnitInverse(const NiQuaternion& rotation);
};
