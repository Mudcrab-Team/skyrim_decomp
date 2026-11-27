// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the contributor-owned image.
// BSParabolicCullingProcess, updateAccumulateFlag, alphaGroupStopIndex, NiAVObject layout and accumulated flag and GetHemisphereMask: CRASHLOGGER_PDB(59818@2026.10.24)
// VisibleMethods and ProcessVisibleObject: GUESS(low) STANDIN
// NiAVObject::OnVisible: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
#pragma once

#include "generated/crashlogger_pdb/types/NiPoint3.h"

struct SphereBound {
    NiPoint3 center;
    float radius;
};

struct BSParabolicCullingProcess;
struct NiAVObject;
struct VisibleMethods {
    void* preceding[52];
    void (*OnVisible)(NiAVObject*, BSParabolicCullingProcess*, unsigned int);
};
struct NiAVObject {
    VisibleMethods* methods;
    unsigned char unknown08[0xDC];
    SphereBound worldBound;
    unsigned int flags;
    static constexpr unsigned int accumulated = 1u << 26;
};
struct BSParabolicCullingProcess {
    unsigned char unknown00[0x11D];
    bool updateAccumulateFlag;
    unsigned char unknown11E[0x301F4 - 0x11E];
    unsigned int alphaGroupStopIndex;
    unsigned int GetHemisphereMask(const SphereBound& bound);
    void ProcessVisibleObject(NiAVObject* object, unsigned int argument);
};
