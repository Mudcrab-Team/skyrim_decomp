// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original partial declarations based on measured fields and cited interfaces.
// GPL-3.0 source for the palette method declaration is cited below.
// NiLookAtInterpolator: EXE_RTTI
// Collapse, ResolveDependencies: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// lookAt, targetName, childInterpolators, padding: GUESS(low)
#pragma once

#include "NiInterpolator.h"

class NiAVObject;

// BSFixedString: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// text: GUESS(low); pointer to the interned text.
class BSFixedString
{
public:
    const char* text;
};

// NiAVObjectPalette: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// GetAVObject: COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
class NiAVObjectPalette : public NiObject
{
public:
    virtual NiAVObject* GetAVObject(BSFixedString& name) = 0;
};

class NiLookAtInterpolator : public NiInterpolator
{
public:
    void Collapse() override;
    bool ResolveDependencies(NiAVObjectPalette* palette) override;

private:
    std::uint8_t padding18[0x8];
    NiAVObject* lookAt;
    BSFixedString targetName;
    std::uint8_t padding30[0x20];
    NiInterpolator* childInterpolators[3];
};
