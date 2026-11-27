// Source exposure: mixed (pinned-image observations and community declarations).
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysMeshUpdateModifier, RegisterStreamables: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysModifier: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// m_kMeshes: SYMBOLS(fo4-pdb)
// MeshArray, unknown10, data, capacity, size, effectiveSize, growBy: STANDIN GUESS(low)
#pragma once
#include "../nimain/NiObject.h"
#include <cstdint>
class NiPSysModifier : public NiObject {
public:
    bool RegisterStreamables(NiStream& stream);
    std::uint8_t unknown10[0x20];
};
struct MeshArray {
    virtual ~MeshArray();
    NiObject** data;
    std::uint16_t capacity;
    std::uint16_t size;
    std::uint16_t effectiveSize;
    std::uint16_t growBy;
};
class NiPSysMeshUpdateModifier : public NiPSysModifier {
public:
    bool RegisterStreamables(NiStream& stream);
    MeshArray m_kMeshes;
};
