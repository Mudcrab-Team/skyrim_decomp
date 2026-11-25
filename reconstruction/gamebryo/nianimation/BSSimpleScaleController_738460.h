// Source exposure: mixed (community declarations, the cited sibling and the pinned image listing).
// Code origin: original reconstruction from the pinned image listing, shaped after the cited sibling.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: BSSimpleScaleController::Update follows fo4-private@1b765c70 src/Game/AI/BSSimpleScaleController.cpp
// Sibling source: fo4-private@1b765c70 src/Game/AI/BSSimpleScaleController.cpp:21
// BSSimpleScaleController::Update, BSSimpleScaleController::scale3D, BSSimpleScaleController::refScale, BSSimpleScaleController::scaleAnimDuration, NiTimeController::startTime, NiTimeController::lastTime, NiTimeController::target, NiAVObject::local, NiTransform::scale: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSSimpleScaleController, NiTimeController, NiObjectNET, NiAVObject, NiTransform: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the members the compared code uses, Update is slot 27 of the full class
// fCellAppTime: SIBLING(fo4-private@1b765c70, author-permission)
// unk00, unk08, unk30, unk34, unk40, unk54: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern float fCellAppTime;

struct NiTransform
{
    std::uint8_t unk00[0x30];
    float scale;  // 30
    std::uint32_t unk34;
};
static_assert(sizeof(NiTransform) == 0x38, "NiTransform size");

class NiObjectNET
{
public:
    virtual ~NiObjectNET();
    std::uint8_t unk08[0x28];  // 08
};
static_assert(sizeof(NiObjectNET) == 0x30, "NiObjectNET size");

class NiAVObject : public NiObjectNET
{
public:
    std::uint8_t unk30[0x18];  // 30
    NiTransform local;         // 48
};

class NiTimeController
{
public:
    virtual ~NiTimeController();
    virtual void Update(float a_time) = 0;  // 27

    std::uint8_t unk08[0x1C];  // 08
    float startTime;           // 24
    float lastTime;            // 28
    std::uint8_t unk2C[0xC];   // 2C
    NiObjectNET* target;       // 38
    NiTimeController* unk40;   // 40
};
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");

class BSSimpleScaleController : public NiTimeController
{
public:
    void Update(float a_time) override;  // 27

    float scale3D;            // 48
    float refScale;           // 4C
    float scaleAnimDuration;  // 50
    std::uint32_t unk54;      // 54
};
static_assert(sizeof(BSSimpleScaleController) == 0x58, "BSSimpleScaleController size");
