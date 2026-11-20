// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkpProcessCollisionData__ToiInfo; size 0x80
#pragma once

#include "hkContactPointPropertiesWithExtendedUserData16.h"
#include "hkContactPoint_68092cba.h"
#include "hkGskCache16.h"
#include "hkPadSpu_float.h"
struct hkpProcessCollisionData__ToiInfo {
    hkContactPoint_68092cba m_contactPoint_0;
    hkPadSpu_float m_time_20;
    hkPadSpu_float m_seperatingVelocity_24;
    char _pad_28[8];
    hkGskCache16 m_gskCache_30;
    hkContactPointPropertiesWithExtendedUserData16 m_properties_40;
};
static_assert(sizeof(hkpProcessCollisionData__ToiInfo) == 128, "hkpProcessCollisionData__ToiInfo layout differs from the PDB");
