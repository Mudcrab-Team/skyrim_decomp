// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// Code origin: Stamped as a twin of matched 0xf011d0 (gamebryo/nimain/NiDefaultAVObjectPalette): source copied, names replaced by placeholders.
// the compared functions from the pinned image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// NiAVObject, BSFixedString: STANDIN COMMUNITY(powerof3/CommonLibSSE@654e55f, GPL-3.0)
// Owner5ece60: GUESS(low) STANDIN
// NiAVObjectPalette, Slot41, paletteMap, scene: GUESS(low) STANDIN
#pragma once
#include "NiDefaultAVObjectPalette.h"

class Owner5ece60 : public NiAVObjectPalette
{
public:
    virtual void* Slot41() const;
    Owner5ece60();
    virtual void SetScene(NiAVObject* a_scene);
    virtual void SetAVObject(BSFixedString& a_name, NiAVObject* a_object);
    virtual ~Owner5ece60();
    virtual NiAVObject* GetAVObject(BSFixedString& a_name);
    virtual void ResetAndFillFromScenegraph();

    PaletteMap paletteMap;  // 10
    NiAVObject* scene;      // 40
};
static_assert(sizeof(Owner5ece60) == 0x48, "Owner5ece60 size");
