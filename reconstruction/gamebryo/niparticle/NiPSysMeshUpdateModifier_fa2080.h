// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; declarations from the labelled community and symbol sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysModifier, NiPSysModifier::ProcessClone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysMeshUpdateModifier, NiPSysMeshUpdateModifier::ProcessClone: CRASHLOGGER_PDB(59818@2026.10.24)
// NiPSysMeshUpdateModifier::m_kMeshes: SYMBOLS(fo4-pdb)
// MeshArray, MeshArray::data, MeshArray::capacity, MeshArray::freeIndex, MeshArray::size, MeshArray::growth, MeshArray::vtable: STANDIN OBSERVED
#pragma once

#include <cstdint>
#include <cstddef>
#include "declarations/NiObject.h"

class NiPSysModifier : public NiObject
{
public:
    void ProcessClone(NiCloningProcess& cloning) override;
    std::uint8_t reserved10[0x20];
};

struct MeshArray
{
    void* vtable;
    NiObject** data;
    std::uint16_t capacity;
    std::uint16_t freeIndex;
    std::uint16_t size;
    std::uint16_t growth;
};

class NiPSysMeshUpdateModifier : public NiPSysModifier
{
public:
    void ProcessClone(NiCloningProcess& cloning) override;
    MeshArray m_kMeshes;
};
static_assert(sizeof(NiPSysModifier) == 0x30, "modifier base extent");
static_assert(offsetof(MeshArray, data) == 8, "mesh storage offset");
static_assert(offsetof(MeshArray, freeIndex) == 0x12, "mesh end offset");
