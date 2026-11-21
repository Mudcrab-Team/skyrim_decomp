// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// the compared functions from the pinned image).
// Code origin: written for this reconstruction from the pinned image listing at 0xefc400 and from
// the declarations in NiAVObject.h and NiObjectNET.h; no community body is copied.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSGeometry: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// BSGeometry::UpdateDownwardPass, BSGeometry::UpdateSelectedDownwardPass, BSGeometry::SetSelectiveUpdateFlags, BSGeometry::RegisterStreamables, BSGeometry::SaveBinary, BSGeometry::LoadBinary, BSGeometry::UpdateWorldBound, BSGeometry::ProcessClone: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiUpdateData, NiStream: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Base-class calls and out-of-unit callees the compared code makes, declared only: BaseUpdateDownwardPass, BaseUpdateSelectedDownwardPass, BaseSetSelectiveUpdateFlags, BaseRegisterStreamables, BaseSaveBinary, BaseLoadBinary,
// UpdateBoundFromFlags: GUESS(low)
// BSGeometryData110: GUESS(low); the MODEL_DATA block at +0x110, saved and loaded by its own callees
// modelBound: GUESS(low); the NiBound at offset 0 of the block, the same member NG declares in BSGeometry's nested MODEL_DATA
// data110: GUESS(low); the block at +0x110, named after its offset like child130 below
// skinInstance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); link saved first, at +0x130
// effect, property: GUESS(low); the two link slots at +0x128 and +0x120, saved after skinInstance
// rendererData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); +0x138, not read by the compared code
// unknown140: GUESS(low); 8 bytes at +0x140 that the compared code never reads
// vertexDesc: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); NG's BSGraphics::VertexDesc, 8 bytes written as one word
// type: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); the type byte at +0x150
// unknown151, unknown152, unknown154: GUESS(low); the tail bytes to sizeof 0x158
#pragma once

#include <cstdint>
#include <cstddef>
#include "NiAVObject.h"

class NiUpdateData;
class NiStream;
class NiCloningProcess;

// BSGeometryData110::SaveBinaryFields, BSGeometryData110::LoadBinaryFields: GUESS(low); declared only
class BSGeometryData110
{
public:
    void SaveBinaryFields(NiStream& a_stream);
    void LoadBinaryFields(NiStream& a_stream);
    // StreamStep: GUESS(low); called three times by LoadBinary with the stream only, declared here
    static void StreamStep(NiStream& a_stream);

    NiBound modelBound;  // 00
};
static_assert(sizeof(BSGeometryData110) == 0x10, "BSGeometryData110 size");

class BSGeometry : public NiAVObject
{
public:
    virtual void UpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // compared: 0xefc6e0
    virtual void UpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);  // compared: 0xefc720
    virtual void SetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);  // compared: 0xefc680
    virtual bool RegisterStreamables(NiStream& a_stream);  // compared: 0xefc380
    virtual void SaveBinary(NiStream& a_stream);  // compared: 0xefc400
    virtual void LoadBinary(NiStream& a_stream);  // compared: 0xefc150
    virtual void UpdateWorldBound();  // compared: 0xefc810
    virtual void ProcessClone(NiCloningProcess& a_cloning);  // compared: 0xefc9f0

    void BaseUpdateDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);
    void BaseUpdateSelectedDownwardPass(NiUpdateData& a_data, std::uint32_t a_arg2);
    void BaseSetSelectiveUpdateFlags(bool& a_selectiveUpdate, bool a_selectiveUpdateTransforms, bool& a_rigid);
    bool BaseRegisterStreamables(NiStream& a_stream);
    void BaseSaveBinary(NiStream& a_stream);
    void BaseLoadBinary(NiStream& a_stream);
    void UpdateBoundFromFlags(NiUpdateData& a_data);

    BSGeometryData110 data110;    // 110
    NiObject*        property;    // 120
    NiObject*        effect;      // 128
    NiObject*        skinInstance;  // 130
    void*            rendererData;  // 138
    void*            unknown140;    // 140
    std::uint64_t    vertexDesc;    // 148
    std::uint8_t     type;          // 150
    std::uint8_t     unknown151;    // 151
    std::uint16_t    unknown152;    // 152
    std::uint32_t    unknown154;    // 154
};
static_assert(sizeof(BSGeometry) == 0x158, "BSGeometry size");
static_assert(offsetof(BSGeometry, skinInstance) == 0x130, "BSGeometry skinInstance");
static_assert(offsetof(BSGeometry, vertexDesc) == 0x148, "BSGeometry vertexDesc");
static_assert(offsetof(BSGeometry, type) == 0x150, "BSGeometry type");
