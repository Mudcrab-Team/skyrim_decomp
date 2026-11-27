// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// NiRefObject, NiObject, BSMultiBoundShape, BSMultiBound: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// NiObject::IsEqual, BSMultiBound::IsEqual, BSMultiBound::unk10, BSMultiBound::data: CRASHLOGGER_PDB(59818@2026.10.24)
// NiRefObject::unk00, BSMultiBound::unk14: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class NiRefObject
{
public:
    std::uint8_t unk00[0x10];
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

class NiObject : public NiRefObject
{
public:
    bool IsEqual(NiObject* a_object);
};
static_assert(sizeof(NiObject) == 0x10, "NiObject size");

class BSMultiBoundShape : public NiObject
{
};

class BSMultiBound : public NiObject
{
public:
    bool IsEqual(NiObject* a_object);

    std::uint32_t unk10;
    std::uint32_t unk14;
    BSMultiBoundShape* data;
};
static_assert(offsetof(BSMultiBound, unk10) == 0x10, "unk10 offset");
static_assert(offsetof(BSMultiBound, data) == 0x18, "data offset");
static_assert(sizeof(BSMultiBound) == 0x20, "BSMultiBound size");
