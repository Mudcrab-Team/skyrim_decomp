// Source exposure: mixed (pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// NiFrustumPlanes, NiPlane, NiPoint3, cullingPlanes, activePlanes, basePlaneStates, unk68 and unk6C: CRASHLOGGER_PDB(59818@2026.10.24)
// CopyFrom, normal and constant: GUESS(low)
#pragma once

#include "../../generated/crashlogger_pdb/types/NiPoint3.h"

struct NiPlane {
    NiPoint3 normal;
    float constant;
    NiPlane& operator=(const NiPlane& other)
    {
        normal.x = other.normal.x;
        normal.y = other.normal.y;
        normal.z = other.normal.z;
        constant = other.constant;
        return *this;
    }
};

struct NiFrustumPlanes {
    NiPlane cullingPlanes[6];
    unsigned int activePlanes;
    unsigned int basePlaneStates;
    unsigned int unk68;
    unsigned int unk6C;

    NiFrustumPlanes& operator=(const NiFrustumPlanes& other);
    void CopyFrom(const NiFrustumPlanes& other)
    {
        for (unsigned int i = 0; i < 6; ++i) {
            cullingPlanes[i] = other.cullingPlanes[i];
        }
        activePlanes = other.activePlanes;
        basePlaneStates = other.basePlaneStates;
        unk68 = other.unk68;
        unk6C = other.unk6C;
    }
};
