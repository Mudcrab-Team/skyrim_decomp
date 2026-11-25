// Source exposure: mixed (community declarations; pinned-image observations).
// Code origin: original; target observations and labelled declarations
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiPSysMeshUpdateModifier, SaveBinary: CRASHLOGGER_PDB(59818@2026.10.24)
// NiStream, NiBinaryStream, NiAVObject, NiStream::SaveLinkID: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiPSysModifier layout: CRASHLOGGER_PDB(59818@2026.10.24)
// NiStreamVTable, NiStreamVTable::SaveLinkID, NiMeshArray, vtable, state, output, writeFn: STANDIN OBSERVED
#pragma once
#include <cstdint>
#include <cstddef>
class NiAVObject;
class NiStream;
struct NiStreamVTable
{
    void* slots[12];
    void (*SaveLinkID)(NiStream*, const NiAVObject*);
};
struct NiBinaryStream
{
    void* vtable;
    std::uint32_t absoluteCurrentPos;
    std::uint32_t alignment;
    void* readFn;
    std::uint32_t (*writeFn)(NiBinaryStream*, const void*, std::uint32_t, std::uint32_t*, std::uint32_t);
};
class NiStream
{
public:
    NiStreamVTable* vtable;
    std::uint8_t state[664];
    NiBinaryStream* output;
};
class NiPSysModifier
{
public:
    void* vtable;
    std::uint32_t referenceCount;
    std::uint32_t alignment0C;
    const char* name;
    std::uint32_t order;
    std::uint32_t alignment1C;
    void* target;
    bool active;
    std::uint8_t alignment29[7];
    void SaveBinary(NiStream& stream);
};
struct NiMeshArray
{
    void* vtable;
    NiAVObject** data;
    std::uint16_t capacity;
    std::uint16_t freeIndex;
    std::uint16_t size;
    std::uint16_t growthSize;
};
class NiPSysMeshUpdateModifier : public NiPSysModifier
{
public:
    NiMeshArray meshes;
    void SaveBinary(NiStream& stream);
};
static_assert(offsetof(NiStream, output) == 0x2A0, "output stream offset");
static_assert(sizeof(NiPSysModifier) == 0x30, "modifier base size");
