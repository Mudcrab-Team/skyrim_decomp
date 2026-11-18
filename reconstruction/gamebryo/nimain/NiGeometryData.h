// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiGeometryData: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// NiGeometryData::GetActiveVertexCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// activeVertexCount: GUESS(low)
#pragma once

#include <cstdint>
#include "../../netimmerse/NiObject.h"

class NiTriShapeData;
class NiTriStripsData;

class NiGeometryData : public NiObject
{
public:
    virtual std::uint16_t GetActiveVertexCount() const;  // compared: 0xefbff0
    // NiGeometryData::AsTriShapeData, NiGeometryData::AsTriStripsData, NiGeometryData::SetActiveVertexCount: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); compared at RVA 0xefc010, 0xefc020, 0xefc030
    virtual NiTriShapeData* AsTriShapeData();  // compared: 0xefc010
    virtual NiTriStripsData* AsTriStripsData();  // compared: 0xefc020
    virtual void SetActiveVertexCount(std::uint16_t a_count);  // compared: 0xefc030

    std::uint16_t activeVertexCount;  // 10
    std::uint8_t unknown12[0x56];  // 12
};
static_assert(sizeof(NiGeometryData) == 0x68, "NiGeometryData size");
