// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Declarations derived from powerof3/CommonLibSSE are GPL-3.0 (its licence).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: mixed; the listed bodies are adapted from community sources, the rest is original
// 0xf002d0 ResetAndFillFromScenegraph.
// Adapted bodies: NiDefaultAVObjectPalette::SetScene, from powerof3/CommonLibSSE@654e55f
// include/RE/N/NiDefaultAVObjectPalette.h:28 (GPL-3.0, stated above); the body is one member store.
// 0xf011d0 NiDefaultAVObjectPalette::SetScene
// 0xf00a10 NiDefaultAVObjectPalette::~NiDefaultAVObjectPalette
#include "NiDefaultAVObjectPalette.h"

// Not compared: defined so that the compiler emits the vftable and, beside it, the
// deleting destructor that is compared (cookbook rule 14).
NiDefaultAVObjectPalette::NiDefaultAVObjectPalette()
{
}

void NiDefaultAVObjectPalette::SetScene(NiAVObject* a_scene)
{
    scene = a_scene;
}

// Body done: RVA 0xf00a10, 83 bytes, NiDefaultAVObjectPalette::~NiDefaultAVObjectPalette; compared
// as the scalar deleting destructor. The target does the NiRefObject cleanup itself, so keep this
// empty definition and the constructor: the inline base destructors in the header make the compiler
// produce the same body.
NiDefaultAVObjectPalette::~NiDefaultAVObjectPalette()
{
}

// Retained generated leaf; its byte-match evidence is renewed with this unit.
// Slot41: GUESS(low); method name inferred from vtable owner and slot
void* NiDefaultAVObjectPalette::Slot41() const
{
    return scene;
}

// 0xf002d0 NiDefaultAVObjectPalette::ResetAndFillFromScenegraph
// The body walks the palette's entry array and releases every occupied entry, then asks the scene to
// fill the emptied palette. Both helpers are declared, not defined: the image implements them.
void NiDefaultAVObjectPalette::ResetAndFillFromScenegraph()
{
    if (scene == nullptr) {
        return;
    }

    PaletteTable& table = paletteMap.table;
    PaletteEntry* entry = table._entries;
    if (entry != nullptr) {
        std::uint32_t remaining = table._capacity;
        if (remaining != 0) {
            do {
                --remaining;
                if (entry->next != nullptr) {
                    ReleasePaletteEntry(entry, &entry->value);
                    entry->next = nullptr;
                    entry->key.~BSFixedString();
                }
                ++entry;
            } while (remaining != 0);
        }
    } else {
        // No storage: the table holds no slots, as the image stores them.
        table._capacity = 0;
    }

    // The occupancy counters restart at the slot count, as the image stores them.
    table._free = table._capacity;
    table._good = table._capacity;

    FillFromScenegraph(scene, this);
}
