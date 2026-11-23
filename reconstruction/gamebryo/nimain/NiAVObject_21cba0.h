// Source exposure: mixed (community headers; pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiObject, BSGeometry: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// NiAVObject, GetRTTI, AsGeometry, skinInstance: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function21cba0, g_skinInstanceRTTI, CastToSkinInstance, unk00, unk01, unk03, unk04, unk05, unk06, unk08: GUESS(low)
#pragma once
#include <cstdint>
class BSGeometry;
class NiObject {
public:
    virtual void unk00();
    virtual void unk01();
    virtual const void* GetRTTI() const;
    virtual void unk03();
    virtual void unk04();
    virtual void unk05();
    virtual void unk06();
    virtual BSGeometry* AsGeometry();
};
class BSGeometry : public NiObject {
public:
    unsigned char unk08[0x120];
    NiObject* skinInstance;
};
extern const char g_skinInstanceRTTI;
class NiAVObject {
public:
    static NiObject* Function21cba0(NiObject* object);
};
