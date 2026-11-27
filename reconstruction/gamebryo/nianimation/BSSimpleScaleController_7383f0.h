// Source exposure: mixed (the listing of the pinned image; names from community declarations and the sibling used by the adapted body).
// Code origin: member names adapted from the sibling; offsets, base constructor and flag edits checked against the listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Game/AI/BSSimpleScaleController.cpp:30
// BSSimpleScaleController, NiTimeController, NiTimeController::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiTimeController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); only the constructor, the flags word and the size are modelled
// BSSimpleScaleController::fStartScale, BSSimpleScaleController::fEndScale, BSSimpleScaleController::fEndTime: SIBLING(fo4-private@1b765c70, author-permission)
// NiTimeController::unk08: GUESS(low)
#pragma once

#include <cstdint>

class NiTimeController
{
public:
    NiTimeController();  // bound: 0xef8230
    virtual ~NiTimeController();

    unsigned char unk08[0x8];  // 08
    std::uint16_t flags;       // 10
    unsigned char unk12[0x36]; // 12
};
static_assert(sizeof(NiTimeController) == 0x48, "NiTimeController size");

class BSSimpleScaleController : public NiTimeController
{
public:
    BSSimpleScaleController();  // compared: 0x7383f0

    float fStartScale;  // 48
    float fEndScale;    // 4C
    float fEndTime;     // 50
    float unk54;        // 54
};
static_assert(sizeof(BSSimpleScaleController) == 0x58, "BSSimpleScaleController size");
