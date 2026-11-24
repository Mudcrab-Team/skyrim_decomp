// Source exposure: mixed (the pinned image listing; names from the sibling).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/FaceGen/BSFaceGenMorphData.cpp:117
// BSFaceGenMorphDataHair, BSFaceGenMorphDataHair::BSFaceGenMorphDataHair, BSFaceGenMorphData: SIBLING(fo4-private@1b765c70, author-permission)
// BSFaceGenMorphDataHair::uiHairMorphIndex, BSFaceGenMorphData::rTri, FffTriFileDataS, FffTriFileDataS::diffMorphList, iSize: GUESS(medium); names from the sibling constructor body
// NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiRefObject::ms_uiObjects, NiRefObject::m_uiRefCount: GUESS(low); object counter and refcount read from the listing
// unknown0c, unknown1c, unknown00: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>
#include <intrin.h>

class NiRefObject
{
public:
    NiRefObject()
        : m_uiRefCount(0)
    {
        _InterlockedIncrement(&ms_uiObjects);  // the engine counts live reference-counted objects atomically
    }

    virtual ~NiRefObject();  // 00

    static volatile long ms_uiObjects;

    std::uint32_t m_uiRefCount;  // 08
    std::uint32_t unknown0c;     // 0C
};
static_assert(sizeof(NiRefObject) == 0x10, "NiRefObject size");

struct FffTriFileDataS
{
    struct MorphList
    {
        std::uint32_t iSize;  // 00
    };

    std::uint8_t unknown00[0x10];  // 00
    MorphList diffMorphList;       // 10
};

class BSFaceGenMorphData : public NiRefObject
{
public:
    BSFaceGenMorphData(const FffTriFileDataS& a_faceGenTri)
        : rTri(a_faceGenTri)
    {
    }

    ~BSFaceGenMorphData() override;

    const FffTriFileDataS& rTri;  // 10
};

class BSFaceGenMorphDataHair : public BSFaceGenMorphData
{
public:
    BSFaceGenMorphDataHair(const FffTriFileDataS& a_faceGenTri);

    ~BSFaceGenMorphDataHair() override;

    std::uint32_t uiHairMorphIndex;  // 18
    std::uint32_t unknown1c;         // 1C
};
static_assert(sizeof(BSFaceGenMorphDataHair) == 0x20, "BSFaceGenMorphDataHair size");
