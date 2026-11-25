// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// Code origin: Stamped as a twin of matched 0xf011d0 (gamebryo/nimain/NiDefaultAVObjectPalette): source copied, names replaced by placeholders.
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// include/RE/N/NiDefaultAVObjectPalette.h:28 (GPL-3.0, stated above); the body is one member store.
// 0x5ece60 Owner5ece60::SetScene
#include "Owner5ece60.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
Owner5ece60::Owner5ece60()
{
}

// guess: same compiled code as matched 0xf011d0 apart from relocated fields; its role here is not established.
void Owner5ece60::SetScene(NiAVObject* a_scene)
{
    scene = a_scene;
}
