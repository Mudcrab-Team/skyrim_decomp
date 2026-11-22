// Source exposure: mixed (local binary analysis and public names).
// Origin: {"generator_family":"const-return","generator_version":"2","name_source":{"confidence":"medium","kind":"public","repository":"CharmedBaryon/CommonLibSSE-NG","revision":"b93280e832f263dbef44e44cbe2936622a02f91a","source":"ng-slot"},"template_digest":"df32415c55896040a11705484c0f0da5801925ec042c4cc3a23c954179756459"}
// Adapted bodies: none. Body synthesized from the bounded leaf template.
// BSMultiBoundSphere: EXE_RTTI
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// member, padding: GUESS(low); storage names invented for the measured member offset
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
#pragma once
#include <cstdint>
// GetType: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
class NiObject;

// IsEqualBase: GUESS(low); address 0xfe4f60, the shared shape comparison the image calls first, bound by hint
bool IsEqualBase(NiObject* a_self, NiObject* a_object);

// centerX, centerY, centerZ, radius: GUESS(low); stand-in without base classes, the object is addressed only through the members the comparison reads
class BSMultiBoundSphere
{
public:
    virtual std::uint32_t GetType() const;
    virtual bool IsEqual(NiObject* a_object);  // compared: 0xfe53a0

    std::uint8_t unknown08[0x10];  // 08
    float centerX;                 // 18
    float centerY;                 // 1C
    float centerZ;                 // 20
    float radius;                  // 24
};
