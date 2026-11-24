// Source exposure: mixed (community headers, CrashLogger layouts, sibling game code, the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Stand-in declarations: NiRTTI, NiObjectNET, NiAVObject, NiTimeController, NiInterpController, NiMultiTargetTransformController.
// NiRTTI, NiObjectNET, NiAVObject, NiTimeController, NiInterpController, NiMultiTargetTransformController, NiBlendTransformInterpolator, NiObjectNET::GetController: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiMultiTargetTransformController::blendInterps, NiMultiTargetTransformController::targets, NiMultiTargetTransformController::numInterps: CRASHLOGGER_PDB(59818@2026.10.24)
// NiMultiTargetTransformController::ms_RTTI, NiInterpController::INVALID_INDEX, GetHighestPriority: SIBLING(fo4-private@1b765c70, author-permission)
// The blend entries are read through a byte offset (72-byte stride, priority byte at 0x1C) as the sibling body does.
// Sibling source: fo4-private@1b765c70 src/Shared/Misc/GlobalFunc.cpp:21
#pragma once

#include <cstdint>

class NiBlendTransformInterpolator;
class NiRTTI;
class NiTimeController;

class NiObjectNET
{
public:
    NiTimeController* GetController(const NiRTTI* a_rtti) const;
};

class NiAVObject : public NiObjectNET
{
};

class NiTimeController
{
public:
    std::uint8_t unk00[0x48];
};

class NiInterpController : public NiTimeController
{
public:
    static const unsigned short INVALID_INDEX;
};

class NiMultiTargetTransformController : public NiInterpController
{
public:
    static NiRTTI ms_RTTI;

    NiBlendTransformInterpolator* blendInterps;  // 48
    NiAVObject** targets;                        // 50
    unsigned short numInterps;                   // 58
};

int GetHighestPriority(NiAVObject* apRoot, NiAVObject* apObj);
