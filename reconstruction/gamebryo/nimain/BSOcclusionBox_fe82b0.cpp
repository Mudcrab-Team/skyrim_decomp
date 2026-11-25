// Code origin: original; hand-written reconstruction from local binary analysis and labelled declarations.
// 0xfe82b0 BSOcclusionBox::~BSOcclusionBox
// Source exposure: mixed
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// BSOcclusionBox, NiRefObject, _refCount, _pad0C: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSMultiBoundShape: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// pMBShape: SIBLING(fo4-private@1b765c70, author-permission)
// NiRefObject: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// BSMultiBoundShape: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// ms_totalObjects: OBSERVED
// unk10, unk18, unk20, unk28, unk30, unk38, unk40, unk48, unk50, unk58, unk60, unk68, unk70, unk78, unk80, unk88, unk90, unk98, unkA0, unkA8, unkB0, unkB8, unkC0, unkC8, unkD0, unkD8, unkE0, unkE8, unkF0, unkF8, unk100, unk108, unk110, unk118, unk120, unk128, unk130, unk138, unk140, unk148, unk150, unk158, unk160, unk168, unk170, unk178, unk180, unk188, unk190, unk1A0, unk1A8, unk1B0, unk1B8, unk1C0, unk1C8, unk1D0, unk1D8, unk1E0: GUESS(low); unaccessed storage.
#include "BSOcclusionBox_fe82b0.h"
#include <intrin.h>

inline NiRefObject::~NiRefObject()
{
    // Object accounting must remain atomic across scene threads.
    _InterlockedDecrement(&ms_totalObjects);
}

BSOcclusionBox::BSOcclusionBox()
{
}

BSOcclusionBox::~BSOcclusionBox()
{
    delete pMBShape;
}
